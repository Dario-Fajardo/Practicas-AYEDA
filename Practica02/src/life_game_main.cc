 /**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 23 Feb 2024
 * @brief Arrchivo main del programa que simula el juego de la vida.
 */

#include "../include/lattice.h"
#include "../include/cell.h"
#include "../include/types.h"
#include "../include/tools.h"
#include <iostream>

int main(int argc, char* argv[]) {
  Position size{0, 0};
  Frontier frontier_type;
  char* input_file{"none"};
  int error_code = CheckParameters(argc, argv, size, frontier_type, input_file);
  if (error_code == 1) {
    return 1;
  }
  Lattice lattice = Lattice::CreateLattice(size, frontier_type, input_file);
  std::string options = "[x]: Salir del programa\n[n]: Generación siguiente\n[L]: Mostrar Y generaciones\n[c]: Alternar modo población\n[s]: Guardar en archivo\n";
  char option;
  bool poblation_flag{false};
  while (option != 'x') {
    if (poblation_flag) {
      std::cout << "Población: " << lattice.Population() << std::endl;
    } else {
      std::cout << lattice;
    }
    std::cout << options << std::endl;
    do {
      std::cout << "Introduzca una opción: \n";
      std::cin >> option;
    } while (option != 'x' && option != 'n' && option != 'L' && option != 'c' && option != 's');
    switch (option) {
      case 'x':
        system("clear");
        break;
      case 'n':
        lattice.NextGeneration();
        break;
      case 'L':
        int generations;
        do {
          std::cout << "Introduzca el número de generaciones a mostrar: ";
          std::cin >> generations;
        } while (generations < 0);
        for (int i{0}; i < generations; ++i) {
          lattice.NextGeneration();
          if (poblation_flag) {
            std::cout << "Población: " << lattice.Population() << std::endl;
          } else {
            std::cout << lattice;
          }
          system("sleep 0.05");
          system("clear");
        }
        break;
      case 'c':
        poblation_flag = !poblation_flag;
        break;
      case 's':
      {
        std::string filename;
        std::string dir{"saves/"};
        std::string extension{".sav"};
        std::cout << "Introduzca el nombre del archivo: ";
        std::cin >> filename;
        filename = dir + filename + extension;
        std::ofstream file(filename, std::ios_base::out);
        file << lattice;
        file.close();
        break;
      }
    }
    system("clear");
  }
  return 0;
}
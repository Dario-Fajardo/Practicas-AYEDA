/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief Arrchivo main del programa que simula un autómata celular elemental.
 */
#include "../include/lattice.h"
#include "../include/cell.h"
#include "../include/tools.h"
#include <ncurses.h>

int main(int argc, char* argv[]) {
  int size;
  Frontier frontier_type;
  std::string input_file{""};
  int error_code = CheckParameters(argc, argv, size, frontier_type, input_file);
  if (error_code == 1) {
    return 1;
  }
  std::cout << "Tamaño del retículo: " << size << std::endl;
  std::cout << "Tipo de frontera: " << frontier_type << std::endl;
  std::cout << "Archivo de entrada: " << input_file << std::endl;
  std::string initial_configuration;
  if (input_file != "") {
    initial_configuration = ExtractInitialConfiguration(input_file);
  }
  Lattice lattice(size, frontier_type, initial_configuration);
  bool running = true;
  while (running) {
    for (int i = 0; i < 20; ++i) {
      std::cout << lattice << std::endl;
      lattice.NextGeneration();
    }
    char answer;
    do {
      std::cout << "¿Desea continuar? (s/n): ";
      std::cin >> answer;
      if (answer == 'n') {
        running = false;
      }
    } while (answer != 's' && answer != 'n');
  }
}
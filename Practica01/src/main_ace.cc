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

/**
 * @brief Función principal del programa.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Array de argumentos pasados al programa.
 * 
 * @return 0 si el programa se ejecuta correctamente, 1 si no.
 */
int main(int argc, char* argv[]) {
  long unsigned int size;
  Frontier frontier_type;
  std::string input_file{""};
  int error_code = CheckParameters(argc, argv, size, frontier_type, input_file);
  if (error_code == 1) {
    return 1;
  }
  std::cout << "Tamaño del retículo: " << size << std::endl;
  std::cout << "Tipo de frontera: " << frontier_type << std::endl;
  std::cout << "Archivo de entrada: " << input_file << std::endl;
  std::cout << "Desea empezar la simulación? (s/n): " << std::endl;
  char answer;
  do {
    std::cin >> answer;
    if (answer == 'n') {
      return 0;
    }
  } while (answer != 's' && answer != 'n');
  std::string initial_configuration;
  if (input_file != "") {
    initial_configuration = ExtractInitialConfiguration(input_file);
  }
  Lattice lattice(size, frontier_type, initial_configuration);
  bool running = true;
  std::ofstream log_file{"logs/last_simulation.txt"};
  while (running) {
    for (int i = 0; i < 30; ++i) {
      std::cout << lattice << std::endl;
      log_file << lattice << std::endl;
      lattice.NextGeneration();
      system("sleep 0.1");
      system("clear");
    }
    std::cout << lattice << std::endl;
    log_file << lattice << std::endl;
    char answer;
    do {
      std::cout << "¿Desea continuar? (s/n): ";
      std::cin >> answer;
      if (answer == 'n') {
        do {
          system("clear");
          std::cout << "¿Desea guardar el estado final en un archivo? (s/n): ";
          std::cin >> answer;
        } while (answer != 's' && answer != 'n');
        if (answer == 's') {
          std::string output_file;
          std::cout << "Introduzca el nombre del archivo de salida: ";
          std::cin >> output_file;
          std::ofstream output_stream{"logs/" + output_file};
          log_file.close();
          std::ifstream log_file{"logs/last_simulation.txt"};
          output_stream << log_file.rdbuf();
        }
        running = false;
        system("clear");
      }
    } while (answer != 's' && answer != 'n');
  }
}
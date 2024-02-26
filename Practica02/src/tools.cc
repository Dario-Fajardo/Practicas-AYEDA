/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 23 Feb 2024
 * @brief En este archivo se declaran utilidades que se usarán en el resto del programa.
 */
#include "../include/tools.h"

/**
 * @brief Comprueba que los parámetros de entrada sean correctos.
 * @param argc Número de argumentos.
 * @param argv Argumentos.
 * @param size Tamaño del tablero.
 * @param frontier_type Tipo de frontera.
 * @param input_file Archivo de entrada.
 * @return int 0 si los parámetros son correctos, 1 si no lo son.
 */
int CheckParameters(const int argc, char *argv[], Position& size, Frontier& frontier_type, char*& input_file) {
  std::vector<std::string> arguments;
  for (int i{1}; i < argc; ++i) {
    arguments.push_back(argv[i]);
  }
  if (argc < 5 || argc > 7) {
    if (find(arguments.begin(), arguments.end(), "-h") != arguments.end() || find(arguments.begin(), arguments.end(), "--help") != arguments.end()) {
      Usage(true);
      return 1;
    } else {
      Usage(false);
      return 1;
    }
  } else {
    bool size_or_file{false};
    for (int i{0}; i < argc - 1; ++i) {
      if (i + 1 == argc) {
        std::cerr << "[ERROR]: No se han especificado suficientes argumentos.\n";
        Usage(false);
        return 1;
      }
      if (arguments[i] == "--border" || arguments[i] == "-b") {
        if (arguments[i + 1] == "reflective") {
          frontier_type = Frontier::reflexed;
        } else if (arguments[i + 1] == "noborder") {
          frontier_type = Frontier::no_frontier;
        } else if (arguments[i + 1] == "periodic") {
          frontier_type = Frontier::periodic;
        } else if (arguments[i + 1] == "open") {
          if (arguments[i + 2] == "0") {
            frontier_type = Frontier::open_cold;
            ++i;
          } else if (arguments[i + 2] == "1") {
            frontier_type = Frontier::open_hot;
            ++i;
          } else {
            std::cerr << "[ERROR]: No se ha especificado un valor válido para el tipo de frontera abierta.\n";
            Usage(false);
            return 1;
          }
        } else {
          std::cerr << "[ERROR]: No se ha especificado un valor válido para el tipo de frontera.\n";
          Usage(false);
          return 1;
        }
        ++i;
      } else if (arguments[i] == "--size" || arguments[i] == "-s") {
        if (size_or_file == true) {
          std::cerr << "[ERROR]: Las opciones --size y --file no pueden ser especificadas simultáneamente.\n";
          Usage(false);
          return 1;
        }
        if (IsDigit(arguments[i + 1]) && IsDigit(arguments[i + 2])) {
          size = Position(std::stoi(arguments[i + 1]), std::stoi(arguments[i + 2]));
          size_or_file = true;
          i += 2;
        } else {
          std::cerr << "[ERROR]: El valor especificado para --size no es válido.\n";
          Usage(false);
          return 1;
        }
      } else if (arguments[i] == "--init" || arguments[i] == "-i") {
        if (size_or_file == true) {
          std::cerr << "[ERROR]: Las opciones --size y --file no pueden ser especificadas simultáneamente.\n";
          Usage(false);
          return 1;
        }
        input_file = argv[i + 2];
        size_or_file = true;
        ++i;
      } else {
        std::cerr << "[ERROR]: Se han especificado opciones no válidas\n";
        Usage(false);
        return 1;
      }  
    }
  }
  return 0;
}

/**
 * @brief Muestra el mensaje de ayuda.
 * @param mode Modo de ayuda. 
 */
void Usage(const bool mode) {
  if (mode == true) {
    std::cout << "Uso: ./life_game [--size <M> <N> | --init <arcihvo>] --border <border>\n";
    std::cout << "Opciones:\n";
    std::cout << "  -h, --help\t\t\tMuestra esta ayuda\n";
    std::cout << "  -s, --size <filas> <columnas>\tEspecifica el tamaño del tablero\n";
    std::cout << "  -b, --border <tipo>\t\tEspecifica el tipo de frontera\n";
    std::cout << "  -i, --init <archivo>\t\tEspecifica el archivo de configuración inicial\n";
  } else {
    std::cerr << "Uso: ./life_game [--size <M> <N> | --init <arcihvo>] --border <border>\n";
    std::cerr << "Pruebe './life_game --help' para más información.\n";
  }
}

/**
 * @brief Comprueba si una cadena de caracteres es un número.
 * @param str Cadena de caracteres.
 * @return bool True si es un número, false si no lo es.
 */
bool IsDigit(const std::string& str) {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}
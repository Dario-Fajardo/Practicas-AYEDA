/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se definen las utilidades que se usarán en el resto del programa.
 */
#include "../include/tools.h"

/**
 * @brief Comprueba que los parámetros pasados al programa sean correctos.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Array de argumentos pasados al programa.
 * @param size Tamaño del retículo que se obtendrá de los argumentos.
 * @param frontier_type Tipo de frontera que se obtendrá de los argumentos.
 * @param input_file Archivo de entrada que se podrá obtener opcionalmente de los argumentos.
 * 
 * @return 0 si los parámetros son correctos, 1 si no lo son para propagar el error.
 */
int CheckParameters(const int argc, char *argv[], long unsigned int& size, Frontier& frontier_type, std::string& input_file) {
  bool size_flag{false};
  bool frontier_flag{false};
  if (argc < 4 || argc > 8) {
    if (argc == 1) {
      Usage(false);
      return 1;
    }
    std::string parameter{argv[1]};
    if (parameter == "--help" || parameter == "-h") {
      Usage(true);
      return 1;
    } else {
      Usage(false);
      return 1;
    }
  } else {
    for (int i = 1; i < argc; i++) {
      std::string parameter{argv[i]};
      if (parameter == "--size" || parameter == "-s") {
        if (i + 1 < argc && IsDigit(std::string(argv[i + 1]))) {
          size = std::stoi(argv[i + 1]);
          if (size < 0) {
            std::cerr << "[ERROR]: El tamaño del retículo debe ser un número entero positivo." << std::endl;
            return 1;
          }
        } else {
          std::cerr << "[ERROR]: Falta el tamaño del retículo." << std::endl;
          return 1;
        }
        size_flag = true;
      } else if (parameter == "--frontier" || parameter == "-f") {
        if (i + 1 < argc) {
          std::string frontier_type_str{argv[i + 1]};
          if (frontier_type_str == "periodic") {
            frontier_type = Frontier::periodic;
          } else if (frontier_type_str == "open") {
            ++i;
            if (i + 1 < argc && IsDigit(std::string(argv[i + 1])) && (std::stoi(argv[i + 1]) >= 0) && (std::stoi(argv[i + 1]) <= 1)) {
              frontier_type = std::stoi(argv[i + 1]) == 0 ? Frontier::fixed_cold : Frontier::fixed_hot;
            } else {
              std::cerr << "[ERROR]: El tipo de frontera abierta debe ser un número entero entre 0 y 1 (fría o caliente)." << std::endl;
              return 1;
            }
          } else {
            std::cerr << "[ERROR]: Tipo de frontera no reconocido." << std::endl;
            return 1;
          }
        } else {
          std::cerr << "[ERROR]: Falta el tipo de frontera." << std::endl;
          return 1;
        }
        frontier_flag = true;
      } else if (parameter == "--init" || parameter == "-i") {
        if (i + 1 < argc) {
          input_file = argv[i + 1];
        } else {
          std::cerr << "[ERROR]: Falta el archivo de entrada." << std::endl;
          return 1;
        }
      } else if (parameter == "--help" || parameter == "-h") {
        Usage(true);
        return 1;
      }
    }
  }
  if (!size_flag || !frontier_flag) {
    Usage(false);
    return 1;
  }
  return 0;
}

/**
 * @brief Muestra el uso del programa o la ayuda.
 * 
 * @param mode Modo en el que se ejecuta la función. False para errores y parámetros mal pasados, true para ayuda.
 */
void Usage(const bool mode) {
  if (!mode) { // Errores y parámetros mal pasados
    std::cerr << "Uso: ./practica01 --size | -s <size> --frontier | -f <periodic|open <0|1>> [--init | -i <input_file>]" << std::endl;
    std::cerr << "Use ./practica01 --help para obtener más información." << std::endl;
  } else { // Help
    std::cout << "AYUDA" << std::endl;
  }
}

/**
 * @brief Comprueba si una cadena de caracteres es un número.
 * 
 * @param str Cadena de caracteres a comprobar.
 * 
 * @return true si la cadena es un número, false si no lo es.
 */
bool IsDigit(const std::string& str) {
  for (char character : str) {
    if (!isdigit(character)) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Extrae la configuración inicial del archivo de entrada.
 * 
 * @param input_file Archivo de entrada.
 * 
 * @return Configuración inicial.
 */
std::string ExtractInitialConfiguration(const std::string& input_file) {
  std::ifstream file(input_file);
  std::string initial_configuration;
  if (file.is_open()) {
    std::getline(file, initial_configuration);
    file.close();
  } else {
    std::cerr << "[ERROR]: No se pudo abrir el archivo de entrada, quizá no exista" << std::endl;
    exit(1);
  }
  return initial_configuration;
}
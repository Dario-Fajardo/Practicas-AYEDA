/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se definen diferentes herramientas que se utilizarán en el programa principal.
 */
#include "Tools.h"

int CheckParameters(bool& dim, bool& size, bool& init, bool& cell, bool& border, bool& help) {
  if (help) {
    Usage(help);
    return 2;
  }
  if (dim && size) {
    if (init) {
      Usage(help);
      return 1;
    }
  } else if (init && cell && border) {
    if (dim || size) {
      Usage(help);
      return 1;
    }
  } else {
    Usage(help);
    return 1;
  }
  return 0;
}

void Usage(const bool& help) {
  if (!help) {
    std::cout << "Modo de uso: ./ACG [[<dim> <size>] | [<init>] <cell> <border>] | [-h|--help]" << std::endl;
    std::cout << "Con --help o -h se muestra la ayuda." << std::endl;
  } else {
    std::cout << "AYUDA:\n";
    std::cout << "--dim <dim>: Número de dimensiones del autómata.\n";
    std::cout << "--size <size>: Tamaño de cada dimensión del autómata.\n";
    std::cout << "--init <init>: Fichero de texto que contiene la configuración inicial del autómata.\n";
    std::cout << "--init es incompatible con --dim y --size.\n";
    std::cout << "--cell <cell>: Tipo de célula que se utilizará en el autómata.\n";
    std::cout << "--border <border>: Tipo de borde que se utilizará en el autómata.\n";
  }
}

int ReadParameters(int argc, char* argv[], int& dim, std::vector<size_t>& size, char*& init, std::string& cell, std::string& border, bool& help) {
  bool dim_flag{false}, size_flag{false}, init_flag{false}, cell_flag{false}, border_flag{false};
  help = false;
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "--dim") {
      dim = std::stoi(argv[++i]);
      dim_flag = true;
    } else if (std::string(argv[i]) == "--size") {
      for (int j = 0; j < dim; j++) {
        size.push_back(std::stoi(argv[++i]));
      }
      size_flag = true;
    } else if (std::string(argv[i]) == "--init") {
      init = argv[++i];
      init_flag = true;
    } else if (std::string(argv[i]) == "--cell") {
      cell = argv[++i];
      cell_flag = true;
    } else if (std::string(argv[i]) == "--border") {
      border = argv[++i];
      border_flag = true;
      if (border == "open") {
        std::string open_type{argv[++i]};
        if (open_type == "0") {
          border = "open cold";
        } else if (open_type == "1") {
          border = "open hot";
        }
      }
    } else if (std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h") {
      help = true;
    }
  }
  return CheckParameters(dim_flag, size_flag, init_flag, cell_flag, border_flag, help);
}
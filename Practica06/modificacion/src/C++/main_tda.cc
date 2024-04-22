/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Implementación del TDA Árbol
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 21 Abr 2024
 * @brief En este archivo se encuentra la función main del programa. 
 */
#include "AB/abb.h"
#include "AB/abe.h"
#include "AB/abb_inverso.h"
#include "Nif/nif.h"
#include <fstream> 

int main(int argc, char* argv[]) {
  AB<Nif>* tree;
  int tree_type;
  std::cout << "Introduzca el tipo de árbol que desea crear (1: ABB, 2: ABE, 3: ABB Inverso): ";
  std::cin >> tree_type;
  if (tree_type == 1) {
    tree = new ABB<Nif>();
  } else if (tree_type == 2) {
    tree = new ABE<Nif>();
  } else if (tree_type == 3) {
    tree = new ABBINV<Nif>();
  } else {
    std::cerr << "Tipo de árbol no válido." << std::endl;
    return 1;
  }
  std::cout << "Introduzca la manera de meter datos al árbol (1: por teclado, 2: aleatorio, 3: fichero): ";
  int input_type;
  std::cin >> input_type;
  switch (input_type) {
    case 1:
      break;
    case 2: {
      std::cout << "Introduzca el número de elementos que desea introducir en el árbol: ";
      int num_elements;
      std::cin >> num_elements;
      for (int i = 0; i < num_elements; i++) {
        Nif nif;
        tree->Insert(nif);
      }
      break;
    }
    case 3: {
      std::string file_name;
      std::cout << "Introduzca el nombre del fichero: ";
      std::cin >> file_name;
      std::ifstream file(file_name);
      if (!file.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        return 1;
      }
      unsigned number;
      while (file >> number) {
        Nif nif(nif);
        tree->Insert(nif);
      }
      break;
    }
    default:
      std::cerr << "Tipo de entrada no válido." << std::endl;
      return 1;
  }
  while (true) {
    std::cout << "Árbol creado." << std::endl;
    tree->InOrder(tree->GetRoot());
    std::cout << std::endl;
    std::cout << "[0] Salir" << std::endl;
    std::cout << "[1] Insertar" << std::endl;
    std::cout << "[2] Buscar" << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
      case 0:
        system("clear");
        return 0;
      case 1: {
        if (input_type == 2) {
          Nif nif;
          tree->Insert(nif);
        } else if (input_type == 1) {
          std::cout << "Introduzca el NIF que desea insertar: ";
          unsigned number;
          std::cin >> number;
          Nif nif(number);
          tree->Insert(nif);
        }
        break; 
      }
      case 2: {
        unsigned number;
        std::cout << "Introduzca el NIF que desea buscar: ";
        std::cin >> number;
        Nif nif{number};
        if (tree->Search(nif)) {
          std::cout << "El NIF está en el árbol." << std::endl;
        } else {
          std::cout << "El NIF no está en el árbol." << std::endl;
        }
        system("read -p 'Press Enter to continue...' var");
        break;
      }
      default:
        std::cerr << "Opción no válida." << std::endl;
        return 1;
    }
    system("clear");
  }
  return 0;
}
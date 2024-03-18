/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 13 Mar 2024
 * @brief En este archivo se encuentra la función main del programa.
 */
#include <iostream>
#include "DispersionFunction/module_dispersion_function.h"
#include "DispersionFunction/pseudorandom_dispersion_function.h"
#include "DispersionFunction/sum_based_dispersion_function.h"
#include "ExplorationFunction/lineal_exploration_function.h"
#include "ExplorationFunction/quadratic_exploration_function.h"
#include "ExplorationFunction/redispersion_exploration_function.h"
#include "ExplorationFunction/double_dispersion_exploration_function.h"
#include "Sequence/dynamic_sequence.h"
#include "Sequence/static_sequence.h"
#include "HashTable/hash_table.h"
#include "Nif/nif.h"

int main(int argc, char* argv[]) {
  DispersionFunction<Nif>* dispersion_function;
  ExplorationFunction<Nif>* exploration_function;
  std::cout << "Práctica 4: Búsqueda por dispersión\n";
  std::cout << "------------------------------------\n";
  std::cout << "Introduzca el tamaño de la tabla hash: \n";
  unsigned table_size;
  std::cin >> table_size;
  std::cout << "Introduzca el tipo de función de dispersión\n";
  std::cout << "[1] Función de dispersión basada en módulo\n";
  std::cout << "[2] Función de dispersión pseudoaleatoria\n";
  std::cout << "[3] Función de dispersión basada en la suma\n";
  int dispersion_function_type;
  std::cin >> dispersion_function_type;
  switch (dispersion_function_type) {
    case 1:
      dispersion_function = new ModuleDispersionFunction<Nif>(table_size);
      break;
    case 2:
      dispersion_function = new PseudorandomDispersionFunction<Nif>(table_size);
      break;
    case 3:
      dispersion_function = new SumBasedDispersionFunction<Nif>(table_size);
      break;
  }
  std::cout << "Utilizaremos dispersión abierta o cerrada?\n";
  std::cout << "[1] Dispersión cerrada\n";
  std::cout << "[2] Dispersión abierta\n";
  int dispersion_type;
  std::cin >> dispersion_type;
  if (dispersion_type == 1) {
    std::cout << "Introduzca el tipo de función de exploración\n";
    std::cout << "[1] Exploración lineal\n";
    std::cout << "[2] Exploración cuadrática\n";
    std::cout << "[3] Redispersión\n";
    std::cout << "[4] Doble dispersión\n";
    int exploration_function_type;
    std::cin >> exploration_function_type;
    switch (exploration_function_type) {
      case 1:
        exploration_function = new LinealExplorationFunction<Nif>;
        break;
      case 2:
        exploration_function = new QuadraticExplorationFunction<Nif>;
        break;
      case 3:
        exploration_function = new RedispersionExplorationFunction<Nif>(*dispersion_function);
        break;
      case 4:
        exploration_function = new DoubleDispersionExplorationFunction<Nif>(*dispersion_function);
        break;
    }
    std::cout << "Introduzca el tamaño de bloque\n";
    unsigned block_size;
    std::cin >> block_size;
    HashTable<Nif, StaticSequence<Nif>> hash_table{table_size, block_size, *dispersion_function, *exploration_function};
    std::string option_menu{"\nMenú de opciones:\n [1] Insertar\n [2] Buscar\n [4] Salir\n"};
    std::cout << option_menu;
    int option;
    std::cin >> option;
    while (option != 4) {
      switch (option) {
        case 1: {
          system("clear");
          std::cout << "Introduzca el NIF a insertar\n";
          unsigned nif;
          std::cin >> nif;
          Nif nif_object{nif};
          if (hash_table.Insert(nif_object))
            std::cout << "NIF " << nif << " insertado correctamente\n";
          else
            std::cout << "No se ha podido insertar el NIF\n";
          break;
        }
        case 2: {
          system("clear");
          std::cout << "Introduzca el NIF a buscar\n";
          unsigned nif_to_search;
          std::cin >> nif_to_search;
          Nif nif_object_to_search{nif_to_search};
          if (hash_table.Search(nif_object_to_search))
            std::cout << "NIF " << nif_to_search << " encontrado\n";
          else
            std::cout << "NIF no encontrado\n";
          break;
        }
      }
      std::cout << option_menu;
      std::cin >> option;
      system("clear");
    }
  } else {
    HashTable<Nif, DynamicSequence<Nif>> hash_table{table_size, *dispersion_function};
    std::string option_menu{"\nMenú de opciones:\n [1] Insertar\n [2] Buscar\n [4] Salir\n"};
    std::cout << option_menu;
    int option;
    std::cin >> option;
    while (option != 4) {
      switch (option) {
        case 1: {
          system("clear");
          std::cout << "Introduzca el NIF a insertar\n";
          unsigned nif;
          std::cin >> nif;
          Nif nif_object{nif};
          if (hash_table.Insert(nif_object))
            std::cout << "NIF " << nif << " insertado correctamente\n";
          else
            std::cout << "No se ha podido insertar el NIF\n";
          break;
        }
        case 2: {
          system("clear");
          std::cout << "Introduzca el NIF a buscar\n";
          unsigned nif_to_search;
          std::cin >> nif_to_search;
          Nif nif_object_to_search{nif_to_search};
          if (hash_table.Search(nif_object_to_search))
            std::cout << "NIF " << nif_to_search << " encontrado\n";
          else
            std::cout << "NIF no encontrado\n";
          break;
        }
      }
      std::cout << option_menu;
      std::cin >> option;
      system("clear");
    }
  }
}
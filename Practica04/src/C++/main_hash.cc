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
  PseudorandomDispersionFunction<Nif> pseudorandom_dispersion_function{10};
  QuadraticExplorationFunction<Nif> quadratic_exploration_function{};
  HashTable<Nif, DynamicSequence<Nif>> hash_table{10, pseudorandom_dispersion_function};
  Nif nif1{79093616};
  Nif nif2{79093617};
  Nif nif3{79093618};
  Nif nif4{79093619};
  Nif nif5{79093620};
  Nif nif6{79093621};
  Nif nif7{79093622};
  Nif nif8{79093623};
  Nif nif9{79093624};
  Nif nif10{79093625};
  Nif nif11{79093626};
  Nif nif12{79093627};
  Nif nif13{79093628};
  Nif nif14{79093629};

  std::cout << "Inserting nif1: " << hash_table.Insert(nif1) << std::endl;
  std::cout << "Inserting nif2: " << hash_table.Insert(nif2) << std::endl;
  std::cout << "Inserting nif3: " << hash_table.Insert(nif3) << std::endl;
  std::cout << "Inserting nif4: " << hash_table.Insert(nif4) << std::endl;
  std::cout << "Inserting nif5: " << hash_table.Insert(nif5) << std::endl;
  std::cout << "Inserting nif6: " << hash_table.Insert(nif6) << std::endl;
  std::cout << "Inserting nif7: " << hash_table.Insert(nif7) << std::endl;
  std::cout << "Inserting nif7: " << hash_table.Insert(nif7) << std::endl;
  std::cout << "Inserting nif8: " << hash_table.Insert(nif8) << std::endl;
  std::cout << "Inserting nif9: " << hash_table.Insert(nif9) << std::endl;
  std::cout << "Inserting nif10: " << hash_table.Insert(nif10) << std::endl;
  std::cout << "Inserting nif11: " << hash_table.Insert(nif11) << std::endl;
  std::cout << "Inserting nif12: " << hash_table.Insert(nif12) << std::endl;
  std::cout << "Inserting nif13: " << hash_table.Insert(nif13) << std::endl;
  std::cout << "Inserting nif14: " << hash_table.Insert(nif14) << std::endl;

  std::cout << "Searching nif1: " << hash_table.Search(nif1) << std::endl;
  std::cout << "Searching nif2: " << hash_table.Search(nif2) << std::endl;
  std::cout << "Searching nif3: " << hash_table.Search(nif3) << std::endl;
  std::cout << "Searching nif4: " << hash_table.Search(nif4) << std::endl;
  std::cout << "Searching nif5: " << hash_table.Search(nif5) << std::endl;
  std::cout << "Searching nif6: " << hash_table.Search(nif6) << std::endl;
  std::cout << "Searching nif7: " << hash_table.Search(nif7) << std::endl;
  std::cout << "Searching nif8: " << hash_table.Search(nif8) << std::endl;
  std::cout << "Searching nif9: " << hash_table.Search(nif9) << std::endl;
  std::cout << "Searching nif10: " << hash_table.Search(nif10) << std::endl;
  std::cout << "Searching nif11: " << hash_table.Search(nif11) << std::endl;
  std::cout << "Searching nif12: " << hash_table.Search(nif12) << std::endl;
  std::cout << "Searching nif13: " << hash_table.Search(nif13) << std::endl;
  std::cout << "Searching nif14: " << hash_table.Search(nif14) << std::endl;
}
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
#include "Nif/nif.h"

int main(int argc, char* argv[]) {
  // Prueba de las clases sequence
  std::cout << "Prueba de la secuencia dinamica" << std::endl;
  DynamicSequence<int> dynamic_sequence;
  dynamic_sequence.Insert(1);
  dynamic_sequence.Insert(2);
  dynamic_sequence.Insert(3);
  dynamic_sequence.Insert(4);
  dynamic_sequence.Insert(5);
  dynamic_sequence.Insert(6);
  dynamic_sequence.Insert(7);
  dynamic_sequence.Insert(8);
  std::cout << "Se inserto el 6? " << dynamic_sequence.Insert(6) << std::endl; 
  std::cout << "Esta el 1? " << dynamic_sequence.Search(1) << std::endl;
  std::cout << "Esta el 6? " << dynamic_sequence.Search(6) << std::endl;

  std::cout << "Prueba de la secuencia estatica" << std::endl;
  StaticSequence<int> static_sequence{5};
  static_sequence.Insert(1);
  static_sequence.Insert(2);
  static_sequence.Insert(3);
  static_sequence.Insert(4);
  static_sequence.Insert(5);
  std::cout << "Se inserto el 6? " << static_sequence.Insert(6) << std::endl;
  std::cout << "Esta el 1? " << static_sequence.Search(1) << std::endl;
  std::cout << "Esta el 6? " << static_sequence.Search(6) << std::endl;
  return 0;
}
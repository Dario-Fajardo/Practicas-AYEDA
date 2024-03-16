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
#include "Nif/nif.h"

int main(int argc, char* argv[]) {
  Nif key(79093616);
  DispersionFunction<Nif>* pseudorandom{new PseudorandomDispersionFunction<Nif>{1000}};
  LinealExplorationFunction<Nif> lineal;
  QuadraticExplorationFunction<Nif> quadratic;
  RedispersionExplorationFunction<Nif> redispersion{*pseudorandom};
  DoubleDispersionExplorationFunction<Nif> double_dispersion{*pseudorandom};
  std::cout << "Lineal: \n";
  for (unsigned i{1}; i < 11; ++i) {
    std::cout << lineal(key, i) << std::endl;
  }
  std::cout << "Quadratic: \n";
  for (unsigned i{1}; i < 11; ++i) {
    std::cout << quadratic(key, i) << std::endl;
  }
  std::cout << "Redispersion: \n";
  for (unsigned i{1}; i < 11; ++i) {
    std::cout << redispersion(key, i) << std::endl;
  }
  std::cout << "Double dispersion: \n";
  for (unsigned i{1}; i < 11; ++i) {
    std::cout << double_dispersion(key, i) << std::endl;
  }
  return 0;
}
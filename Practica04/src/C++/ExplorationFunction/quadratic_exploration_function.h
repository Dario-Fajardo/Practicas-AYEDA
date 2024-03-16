/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 16 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase QuadraticExplorationFunction, 
 *        hija de la clase abstracta ExplorationFunction utilizada para implementar este 
 *        tipo de función de exploración
 */
#ifndef QUADRATIC_EXPLORATION_FUNCTION_H
#define QUADRATIC_EXPLORATION_FUNCTION_H

#include "exploration_function.h"

template<class Key>
class QuadraticExplorationFunction : public ExplorationFunction<Key> {
 public:
  QuadraticExplorationFunction() = default;
  unsigned operator() (const Key& key, unsigned iteration) const override { return iteration * iteration; }
};

#endif  // QUADRATIC_EXPLORATION_FUNCTION_H
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 16 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase DoubleDispersionExplorationFunction, 
 *        hija de la clase abstracta ExplorationFunction utilizada para implementar este 
 *        tipo de función de exploración
 */
#ifndef DOUBLE_DISPERSION_EXPLORATION_FUNCTION_H
#define DOUBLE_DISPERSION_EXPLORATION_FUNCTION_H

#include "exploration_function.h"

template<class Key>
class DoubleDispersionExplorationFunction : public ExplorationFunction<Key> {
 public:
  DoubleDispersionExplorationFunction(const DispersionFunction<Key>& f) : f_{const_cast<DispersionFunction<Key>&>(f)} {}
  unsigned operator() (const Key& key, unsigned iterator) const override { return f_(key) * iterator; };
 private:
  DispersionFunction<Key>& f_;
};

#endif  // DOUBLE_DISPERSION_EXPLORATION_FUNCTION_H
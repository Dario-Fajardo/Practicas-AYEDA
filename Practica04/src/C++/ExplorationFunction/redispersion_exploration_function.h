/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 16 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase RedispersionExplorationFunction, 
 *        hija de la clase abstracta ExplorationFunction utilizada para implementar este 
 *        tipo de función de exploración
 */
#ifndef REDISPERSION_EXPLORATION_FUNCTION_H
#define REDISPERSION_EXPLORATION_FUNCTION_H

#include "exploration_function.h"
#include "../DispersionFunction/pseudorandom_dispersion_function.h"

template<class Key>
class RedispersionExplorationFunction : public ExplorationFunction<Key> {
 public:
  RedispersionExplorationFunction(const DispersionFunction<Key>& f) : f_{const_cast<DispersionFunction<Key>&>(f)} {};
  unsigned operator() (const Key& key, unsigned iteration) const override {
    unsigned desp{0};
    srand(key);
    for (unsigned i{0}; i < iteration; ++i) {
      desp = rand();
    }
    return desp & f_.GetTableSize();
  }
 private:
  DispersionFunction<Key>& f_;
};

#endif  // REDISPERSION_EXPLORATION_FUNCTION_H
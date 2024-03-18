/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 13 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase PseudorandomDispersionFunction, hija de la clase abstracta DispersionFunction
 *        utilizada para implementar este tipo de función de dispersion
 */
#ifndef PSEUDORANDOM_DISPERSION_FUNCTION_H
#define PSEUDORANDOM_DISPERSION_FUNCTION_H

#include "dispersion_function.h"
#include <cstdlib>

template<class Key>
class PseudorandomDispersionFunction : public DispersionFunction<Key> {
 public:
  PseudorandomDispersionFunction(const unsigned table_size) : table_size_(table_size) {};
  unsigned operator() (const Key& key) const override { srand(long(key)); return rand() % table_size_; };
  unsigned GetTableSize() const override { return table_size_; };
 private:
  unsigned table_size_;
};

#endif  // PSEUDORANDOM_DISPERSION_FUNCTION_H
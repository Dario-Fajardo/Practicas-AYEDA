/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Algoritmos de ordenación
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 7 Abr 2024
 * @brief En este archivo se declara la clase abstracta SortMethod
 *        usada para crear clases para distintos algoritmos de ordenación
 */
#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include "../Sequence/static_sequence.h"
#include "../Functions/functions.h"

template<class Key>
class SortMethod {
 public:
  SortMethod(StaticSequence<Key> sequence) : sequence_{sequence} {}
  virtual void Sort(void) = 0;
 protected:
  StaticSequence<Key> sequence_;
};

#endif
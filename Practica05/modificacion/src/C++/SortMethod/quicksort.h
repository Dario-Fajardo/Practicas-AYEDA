/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Algoritmos de ordenación
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 7 Abr 2024
 * @brief En este archivo se declara la clase Quicksort
 *        que servirá para implementar el algoritmo de ordenación
 *        Quicksort
 */
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sort_method.h"

template<class Key>
class Quicksort : public SortMethod<Key> {
 public:
  Quicksort(StaticSequence<Key> sequence) : SortMethod<Key>(sequence) {}
  void Sort() override;
};

template<class Key> void Quicksort<Key>::Sort() {
  Quick(this->sequence_, this->sequence_.Size(), 0, this->sequence_.Size() - 1, this->comparisons_, this->swaps_);
}

#endif
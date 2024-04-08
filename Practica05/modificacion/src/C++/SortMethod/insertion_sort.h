/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Algoritmos de ordenación
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 7 Abr 2024
 * @brief En este archivo se declara la clase InsertionSort
 *        que servirá para implementar el algoritmo de ordenación
 *        por inserción
 */
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort_method.h"

template<class Key>
class InsertionSort : public SortMethod<Key> {
 public:
  InsertionSort(StaticSequence<Key> sequence) : SortMethod<Key>(sequence) {}
  void Sort() override;
};

template<class Key> void InsertionSort<Key>::Sort() {
  Insertion(this->sequence_, this->sequence_.Size(), this->comparisons_, this->swaps_);
}

#endif
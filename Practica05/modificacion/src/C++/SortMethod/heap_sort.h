/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Algoritmos de ordenación
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 7 Abr 2024
 * @brief En este archivo se declara la clase HeapSort
 *        que servirá para implementar el algoritmo de ordenación
 *        por heap
 */
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sort_method.h"

template<class Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(StaticSequence<Key> sequence) : SortMethod<Key>(sequence) {}
  void Sort() override;
};

template<class Key> void HeapSort<Key>::Sort() {
  Heap(this->sequence_, this->sequence_.Size(), this->comparisons_, this->swaps_);
}

#endif
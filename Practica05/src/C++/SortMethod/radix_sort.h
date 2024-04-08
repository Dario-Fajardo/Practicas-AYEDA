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
 *        radixshort
 */
#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "sort_method.h"

template<class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(StaticSequence<Key> sequence) : SortMethod<Key>(sequence) {}
  void Sort() override;
};

template<class Key> 
void RadixSort<Key>::Sort() {
  Radix(this->sequence_, this->sequence_.Size());
}

#endif
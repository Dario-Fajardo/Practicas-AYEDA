/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Algoritmos de ordenación
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 7 Abr 2024
 * @brief En este archivo es una librería de funciones que implementan
 *        distintos algoritmos de ordenación
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../Sequence/static_sequence.h"
#include <iostream>

template<class Key>
void Insertion(StaticSequence<Key>& sequence, int size) {
  for (int i = 1; i < size; ++i) {
    int j = i - 1;
    Key key = sequence[i];
    while (j >= 0 && key < long(sequence[j])) {
      sequence[j + 1] = sequence[j];
      --j;
    }
    sequence[j + 1] = key;
  }
}

template<class Key>
void Quick(StaticSequence<Key>& sequence, int size, int ini, int fin) {
  int i = ini;
  int f = fin;
  Key pivot = sequence[(i + f) / 2];
  while (i <= f) {
    while (sequence[i] < long(pivot)) {
      ++i;
    }
    while (sequence[f] > long(pivot)) {
      --f;
    }
    if (i <= f) {
      Key aux = sequence[i];
      sequence[i] = sequence[f];
      sequence[f] = aux;
      ++i;
      --f;
    }
  }
  if (ini < f) {
    Quick(sequence, size, ini, f);
  }
  if (i < fin) {
    Quick(sequence, size, i, fin);
  }
}

template<class Key>
void Heapify(StaticSequence<Key>& sequence, int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < size && long(sequence[left]) > long(sequence[largest])) {
    largest = left;
  }
  if (right < size && long(sequence[right]) > long(sequence[largest])) {
    largest = right;
  }
  if (largest != i) {
    Key aux = sequence[i];
    sequence[i] = sequence[largest];
    sequence[largest] = aux;
    Heapify(sequence, size, largest);
  }
}

template<class Key>
void Heap(StaticSequence<Key>& sequence, int size) {
  for (int i = size / 2 - 1; i >= 0; --i) {
    Heapify(sequence, size, i);
  }
  for (int i = size - 1; i > 0; --i) {
    Key aux = sequence[0];
    sequence[0] = sequence[i];
    sequence[i] = aux;
    Heapify(sequence, i, 0);
  }
}

template<class Key>
void DeltaSort(StaticSequence<Key>& sequence, int size, int delta) {
  for (int i = delta; i < size; ++i) {
    int j = i - delta;
    Key key = sequence[i];
    while (j >= 0 && key < long(sequence[j])) {
      sequence[j + delta] = sequence[j];
      j -= delta;
    }
    sequence[j + delta] = key;
  }
}

template<class Key>
void Shell(StaticSequence<Key>& sequence, int size) {
  float alfa;
  std::cout << "Introduzca el valor de alfa: ";
  std::cin >> alfa;
  int delta = size * alfa;
  while (delta > 1) {
    delta = delta / 2;
    DeltaSort(sequence, size, delta);
  }
}

template<class Key>
void Radix(StaticSequence<Key>& sequence, int size) {
  int max = long(sequence[0]);
  for (int i = 1; i < size; ++i) {
    if (long(sequence[i]) > max) {
      max = long(sequence[i]);
    }
  }
  for (int exp = 1; max / exp > 0; exp *= 10) {
    int output[size];
    int count[10] = {0};
    for (int i = 0; i < size; ++i) {
      count[(long(sequence[i]) / exp) % 10]++;
    }
    for (int i = 1; i < 10; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; --i) {
      output[count[(long(sequence[i]) / exp) % 10] - 1] = sequence[i];
      count[(long(sequence[i]) / exp) % 10]--;
    }
    for (int i = 0; i < size; ++i) {
      sequence[i] = output[i];
    }
  }
}

#endif
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Algoritmos de ordenación
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 7 Abr 2024
 * @brief En este archivo se encuentra la función main del programa
 */
#include "Sequence/static_sequence.h"
#include "SortMethod/insertion_sort.h"
#include "SortMethod/quicksort.h"
#include "SortMethod/heap_sort.h"
#include "SortMethod/shell_sort.h"
#include "SortMethod/radix_sort.h"
#include "Nif/nif.h"
#include <iostream>


int main(int argc, char* argv[]) {
  StaticSequence<Nif> sequence{100};
  for (int i = 0; i < 100; i++) {
    Nif nif;
    sequence[i] = nif;
  }
  InsertionSort<Nif> insertion_sort{sequence};
  insertion_sort.Sort();
  std::cout << "Insertion sort: " << insertion_sort.GetComparisons() << " comparisons, " << insertion_sort.GetSwaps() << " swaps" << std::endl;
  StaticSequence<Nif> sequence2{100};
  for (int i = 0; i < 100; i++) {
    Nif nif;
    sequence2[i] = nif;
  }
  Quicksort<Nif> quick_sort{sequence2};
  quick_sort.Sort();
  std::cout << "Quicksort: " << quick_sort.GetComparisons() << " comparisons, " << quick_sort.GetSwaps() << " swaps" << std::endl;
  StaticSequence<Nif> sequence3{100};
  for (int i = 0; i < 100; i++) {
    Nif nif;
    sequence3[i] = nif;
  }
  HeapSort<Nif> heap_sort{sequence3};
  heap_sort.Sort();
  std::cout << "Heapsort: " << heap_sort.GetComparisons() << " comparisons, " << heap_sort.GetSwaps() << " swaps" << std::endl;
  StaticSequence<Nif> sequence4{100};
  for (int i = 0; i < 100; i++) {
    Nif nif;
    sequence4[i] = nif;
  }
  ShellSort<Nif> shell_sort{sequence4};
  shell_sort.Sort();
  std::cout << "Shellsort: " << shell_sort.GetComparisons() << " comparisons, " << shell_sort.GetSwaps() << " swaps" << std::endl;
  StaticSequence<Nif> sequence5{100};
  for (int i = 0; i < 100; i++) {
    Nif nif;
    sequence5[i] = nif;
  }
  RadixSort<Nif> radix_sort{sequence5};
  radix_sort.Sort();
  std::cout << "Radixsort: " << radix_sort.GetComparisons() << " comparisons, " << radix_sort.GetSwaps() << " swaps" << std::endl;
  return 0;
}
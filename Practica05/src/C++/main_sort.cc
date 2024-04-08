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
  std::cout << "Introduzca el tamaño de la secuencia: ";
  int sequence_size;
  std::cin >> sequence_size;
  system("clear");
  std::cout << "Introduzca el método de ordenación a utilizar: \n";
  std::cout << "[1] Inserción" << std::endl;
  std::cout << "[2] Quicksort" << std::endl;
  std::cout << "[3] Heapsort" << std::endl;
  std::cout << "[4] Shellsort" << std::endl;
  std::cout << "[5] Radixsort" << std::endl;
  int sort_method;
  std::cin >> sort_method;
  std::cout << "Introduzca como se añadirán datos a la secuencia: \n";
  std::cout << "[1] Manual" << std::endl;
  std::cout << "[2] Automático" << std::endl;
  std::cout << "[3] Fichero" << std::endl;
  int input_method;
  std::cin >> input_method;
  
  StaticSequence<Nif> sequence(sequence_size);
  switch (input_method) {
    case 1: {
      std::cout << "Introduzca los elementos de la secuencia: ";
      for (int i = 0; i < sequence_size; ++i) {
        long nif;
        std::cin >> nif;
        Nif element(nif);
        sequence[i] = element;
      }
      break;
    }
    case 2: {
      for (int i = 0; i < sequence_size; ++i) {
        Nif element;
        sequence[i] = element;
      }
      break;
    }
    case 3: {
      std::string file_name;
      std::cout << "Introduzca el nombre del fichero: ";
      std::cin >> file_name;
      std::ifstream file(file_name, std::ios_base::in);
      if (!file.is_open()) {
        std::cerr << "Error al abrir el fichero" << std::endl;
        return 1;
      }
      for (int i = 0; i < sequence_size; ++i) {
        long nif;
        file >> nif;
        Nif element(nif);
        sequence[i] = element;
      }
      break;
    }
  }
  system("clear");
  std::cout << "Secuencia original: \n";
  sequence.Print();

  switch (sort_method) {
    case 1: {
      InsertionSort<Nif> insertion_sort{sequence};
      insertion_sort.Sort();
      break;
    }
    case 2: {
      Quicksort<Nif> quicksort{sequence};
      quicksort.Sort();
      break;
    }
    case 3: {
      HeapSort<Nif> heap_sort{sequence};
      heap_sort.Sort();
      break;
    }
    case 4: {
      ShellSort<Nif> shell_sort{sequence};
      shell_sort.Sort();
      break;
    }
    case 5: {
      RadixSort<Nif> radix_sort{sequence};
      radix_sort.Sort();
      break;
    }
  }
  std::cout << "Secuencia ordenada: \n";
  sequence.Print();
  return 0;
}
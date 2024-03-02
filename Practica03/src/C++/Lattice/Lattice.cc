/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abstracta Lattice. Que define como se 
 *        implementará el retículo en un autómata celular general.
 */
#include "Lattice.h"
#include "../Cell/Cell.h"

/**
 * @brief Constructor de la clase Lattice
 * @param size número de células del retículo
 * @param factory fábrica de células
 * @param dimensions número de dimensiones del retículo
 * @param rows número de filas del retículo
 * @param columns número de columnas del retículo
 */
Lattice::Lattice(const size_t size, const FactoryCell& factory, int dimensions, size_t rows, size_t columns) : size_{size}, rows_{rows}, columns_{columns}, factory_{const_cast<FactoryCell&>(factory)} {
  unidimensional_lattice_.reserve(size_);
  int number_of_cells = static_cast<int>(size_);
  for (int i = 0; i < number_of_cells; i++) {
    PositionDim<1> position{1, i};
    unidimensional_lattice_.emplace_back(factory.CreateCell(position, State::Dead));
  }
}

/**
 * @brief Constructor de la clase Lattice a partir de un archivo
 * @param filename nombre del archivo
 * @param factory fábrica de células 
 */
Lattice::Lattice(const char* filename, const FactoryCell& factory) : factory_{const_cast<FactoryCell&>(factory)} {
  std::ifstream file;
  file.open(filename);
  if (!file.is_open()) {
    std::cerr << "[ERROR]: No se pudo abrir el archivo, compruebe si existe" << std::endl;
    exit(1);
  }
  int dimensions;
  file >> dimensions;
  if (dimensions == 1) {
    file >> size_;
  } else {
    file >> rows_;
    file >> columns_;
    size_ = rows_ * columns_;
  }
  int number_of_cells = static_cast<int>(size_);
  for (int i = 0; i < number_of_cells; i++) {
    int state;
    file >> state;
    unidimensional_lattice_[i] = factory.CreateCell(PositionDim<1>{1, i}, static_cast<State>(state));
  }
  file.close();
}

// /**
//  * @brief Destructor de la clase Lattice
//  */
// Lattice::~Lattice() {
//   std::cerr << "Destructor de Lattice" << std::endl;
//   for (size_t i = 0; i < size_; i++) {
//     std::cerr << "Borrando célula " << i << std::endl;
//     lattice_[i] = nullptr;
//     delete lattice_[i];
//   }
//   delete[] lattice_;
// }

/**
 * @brief Operador de inserción para la clase Lattice
 * @param os flujo de salida
 * @param lattice retículo 
 */
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  return lattice.Display(os);
}
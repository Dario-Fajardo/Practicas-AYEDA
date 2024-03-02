/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abstracta Lattice2DReflective. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser bidimenstional y con forntera reflectiva.
 */
#include "Lattice2D_reflective.h"

/**
 * @brief Destructor de la clase Lattice2DReflective
 */
Lattice2DReflective::~Lattice2DReflective() {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      delete bidimensional_lattice_[i][j];
    }
  }
  bidimensional_lattice_.~vector();
}

/**
 * @brief Método que devuelve una referencia a la célula en la posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DReflective::GetCell(const Position& position) const {
  size_t row = position[0];
  size_t column = position[1];
  if (row < 0) {
    row = abs(row);
  } else if (row >= rows_) {
    row = (rows_ - 1) - (row % rows_ - 1);
  }
  if (column < 0) {
    column = abs(column);
  } else if (column >= columns_) {
    column = (columns_ - 1) - (column % columns_ - 1);
  }
  return *bidimensional_lattice_[row][column];
}

/**
 * @brief Sobrecarga del operador [] para acceder a una célula en una posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DReflective::operator[](const Position& position) const {
  return GetCell(position);
}
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

Lattice2DReflective::Lattice2DReflective(const size_t size, const FactoryCell& factory, const size_t& rows, const size_t& columns) : Lattice2D(size, factory, rows, columns) {
    char answer{'s'};
  do {
    std::cout << "Quieres poner alguna célula en estado viva? (s/n)" << std::endl;
    do {
      std::cin >> answer;
    } while (answer != 's' && answer != 'n');
    if (answer == 's') {
      size_t row, column;
      do {
        std::cout << "Introduce la posición de la célula que quieres poner en estado viva: ";
        std::cin >> row >> column;
      } while (row < 0 || row >= rows_ || column < 0 || column >= columns_);
      lattice_[row][column]->SetState(State::Alive);
    }
  } while(answer == 's'); 
}

void Lattice2DReflective::NextGeneration() {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      lattice_[i][j]->NextState(*this);
    }
  }
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      lattice_[i][j]->UpdateState();
    }
  }
}

/**
 * @brief Método que devuelve una referencia a la célula en la posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DReflective::GetCell(const Position& position) const {
  int row = position[0];
  int column = position[1];
  int rows = rows_;
  int columns = columns_;
  if (row < 0) {
    row = abs(row);
  } else if (row >= rows) {
    row = rows - (row - rows) - 1;
  }
  if (column < 0) {
    column = abs(column);
  } else if (column >= columns) {
    column = columns - (column - columns) - 1;
  }
  return *lattice_[row][column];
}

/**
 * @brief Sobrecarga del operador [] para acceder a una célula en una posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DReflective::operator[](const Position& position) const {
  return GetCell(position);
}
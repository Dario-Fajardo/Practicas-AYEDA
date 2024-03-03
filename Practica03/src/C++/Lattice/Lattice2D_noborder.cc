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
#include "Lattice2D_noborder.h"

Lattice2DNoBorder::Lattice2DNoBorder(const size_t size, const FactoryCell& factory, const size_t& rows, const size_t& columns) : Lattice2D(size, factory, rows, columns) {
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

/**
 * @brief Método que devuelve una referencia a la célula en la posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DNoBorder::GetCell(const Position& position) const {
  int row = position[0];
  int column = position[1];
  int rows = rows_;
  int columns = columns_;
  if (row < 0 || row >= rows || column < 0 || column >= columns) {
    return *factory_.CreateCell(position, State::Dead);
  }
  return *lattice_[row][column];
}

/**
 * @brief Método que devuelve una referencia a la célula en la posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DNoBorder::GetCell(const Position& position) {
  int row = position[0];
  int column = position[1];
  int rows = rows_;
  int columns = columns_;
  if (row < 0 || row >= rows || column < 0 || column >= columns) {
    return *factory_.CreateCell(position, State::Dead);
  }
  return *lattice_[row][column];
}

/**
 * @brief Sobrecarga del operador [] para acceder a una célula en una posición dada
 * @param position Posición de la célula
 * @return Célula en la posición dada
 */
Cell& Lattice2DNoBorder::operator[](const Position& position) const {
  return GetCell(position);
}

void Lattice2DNoBorder::NextGeneration() {
  FrontierExpansion();
  for (size_t i{0}; i < rows_; i++) {
    for (size_t j{0}; j < columns_; j++) {
      lattice_[i][j]->NextState(*this);
    }
  }
  for (size_t i{0}; i < rows_; i++) {
    for (size_t j{0}; j < columns_; j++) {
      lattice_[i][j]->UpdateState();
    }
  }
}

void Lattice2DNoBorder::FrontierExpansion() {
  bool top{false}, bottom{false}, left{false}, right{false};
  for (size_t i{0}; i < rows_; i++) {
    for (size_t j{0}; j < columns_; j++) {
      if (i == 0 && lattice_[i][j]->GetState() == State::Alive) {
        top = true;
      }
      if (i == rows_ - 1 && lattice_[i][j]->GetState() == State::Alive) {
        bottom = true;
      }
      if (j == 0 && lattice_[i][j]->GetState() == State::Alive) {
        left = true;
      }
      if (j == columns_ - 1 && lattice_[i][j]->GetState() == State::Alive) {
        right = true;
      }
    }
  }
  if (top) {
    Position* new_position = new PositionDim<2>{2, 0, 0};
    lattice_.insert(lattice_.begin(), std::vector<Cell*>(columns_, factory_.CreateCell(*new_position, State::Dead)));
    rows_++;
  }
  if (bottom) {
    Position* new_position = new PositionDim<2>{2, 0, 0};
    lattice_.push_back(std::vector<Cell*>(columns_, factory_.CreateCell(*new_position, State::Dead)));
    rows_++;
  }
  if (left) {
    for (size_t i{0}; i < rows_; i++) {
      Position* new_position = new PositionDim<2>{2, 0, 0};
      lattice_[i].insert(lattice_[i].begin(), factory_.CreateCell(*new_position, State::Dead));
    }
    columns_++;
  }
  if (right) {
    for (size_t i{0}; i < rows_; i++) {
      Position* new_position = new PositionDim<2>{2, 0, 0};
      lattice_[i].push_back(factory_.CreateCell(*new_position, State::Dead));
    }
    columns_++;
  }
  Resize_(rows_, columns_);
}

void Lattice2DNoBorder::Resize_(size_t rows, size_t columns) {
  rows_ = rows;
  columns_ = columns;
  lattice_.resize(rows_);
  for (size_t i{0}; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (size_t j{0}; j < columns_; j++) {
      Position* new_position = new PositionDim<2>{2, i, j};
      lattice_[i][j] = factory_.CreateCell(*new_position, lattice_[i][j]->GetState());
    }
  }
}
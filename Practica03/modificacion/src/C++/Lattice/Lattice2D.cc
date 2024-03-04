/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abstracta Lattice2D. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser bidimensional.
 */
#include "Lattice2D.h"

Lattice2D::Lattice2D(const size_t size, const FactoryCell& factory, const size_t& rows, const size_t& columns) : Lattice(size, factory), rows_{rows}, columns_{columns} {
  lattice_.resize(rows_);
  for (size_t i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (size_t j = 0; j < columns_; j++) {
      Position* position = new PositionDim<2>(2, i, j);
      lattice_[i][j] = factory_.CreateCell(*position, State::Dead);
    }
  }
}

Lattice2D::Lattice2D(const char* file_name, const FactoryCell& factory) : Lattice(0, factory) {
  std::ifstream file(file_name, std::ios_base::in);
  if (!file.is_open()) {
    std::cerr << "Error: file could not be opened." << std::endl;
    exit(1);
  }
  file >> rows_;
  file >> columns_;
  lattice_.resize(rows_);
  for (size_t i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (size_t j = 0; j < columns_; j++) {
      Position* position = new PositionDim<2>(2, i, j);
      lattice_[i][j] = factory_.CreateCell(*position, State::Dead);
    }
  }
  std::string line;
  int row{0};
  char cell;
  while (std::getline(file, line)) {
    for (size_t j{0}; j < line.size(); j++) {
      cell = line[j];
      if (cell == 'X') {
        lattice_[row][j]->SetState(State::Alive);
      } else {
        lattice_[row][j]->SetState(State::Dead);
      }
    }
    row++;
  }
  file.close();
}

Neighbourhood Lattice2D::GetNeighbours(const Position& position, const int& mode) const {
  Neighbourhood neighbours;
  if (mode == 0) {
    Position* left = new PositionDim<2>(2, position[0], position[1] - 1);
    Position* right = new PositionDim<2>(2, position[0], position[1] + 1);
    neighbours = Neighbourhood{GetCell(*left).GetState(), GetCell(*right).GetState(), State::Dead, State::Dead, State::Dead, State::Dead, State::Dead, State::Dead};
  } else {
    Position* up_left = new PositionDim<2>(2, position[0] - 1, position[1] - 1);
    Position* up = new PositionDim<2>(2, position[0] - 1, position[1]);
    Position* up_right = new PositionDim<2>(2, position[0] - 1, position[1] + 1);
    Position* left = new PositionDim<2>(2, position[0], position[1] - 1);
    Position* right = new PositionDim<2>(2, position[0], position[1] + 1);
    Position* down_left = new PositionDim<2>(2, position[0] + 1, position[1] - 1);
    Position* down = new PositionDim<2>(2, position[0] + 1, position[1]);
    Position* down_right = new PositionDim<2>(2, position[0] + 1, position[1] + 1);
    neighbours = Neighbourhood{GetCell(*up_left).GetState(), GetCell(*up).GetState(), GetCell(*up_right).GetState(), GetCell(*left).GetState(), GetCell(*right).GetState(), GetCell(*down_left).GetState(), GetCell(*down).GetState(), GetCell(*down_right).GetState()};
  }
  return neighbours;
}

size_t Lattice2D::Population() const {
  size_t population = 0;
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      if (lattice_[i][j]->GetState() == State::Alive) {
        population++;
      }
    }
  }
  return population;
}

std::ostream& Lattice2D::Display(std::ostream& os) const {
  std::cout << "Rows: " << rows_ << "Columns: " << columns_ << std::endl;
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      os << *lattice_[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 23 Feb 2024
 * @brief En este archivo se define la clase Lattice. Que imlementa el comportamiento del retículo en un autómata celular.
 */
#include "../include/lattice.h"
#include "../include/cell.h"

Lattice Lattice::CreateLattice(const Position& size, Frontier frontier_type, const char* input_file) {
  if (input_file == "none") {
    return Lattice(size.first, size.second, frontier_type);
  }
  return Lattice(input_file, frontier_type);
}

Lattice::Lattice(int rows, int columns, Frontier frontier_type) {
  rows_ = rows;
  columns_ = columns;
  frontier_type_ = frontier_type;
  cells_.resize(rows_);
  for (int i{0}; i < rows_; ++i) {
    cells_[i].resize(columns_);
  }
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < columns_; ++j) {
      cells_[i][j] = Cell(Position(i, j), State::dead);
    }
  }
  frontier_cell_ = Cell(State::dead);
  SetCells_();
}

Lattice::Lattice(const char* filename, Frontier frontier_type) {
  frontier_type_ = frontier_type;
  std::ifstream file(filename, std::ios_base::in);
  if (!file.is_open()) {
    std::cerr << "[ERROR]: No se pudo abrir el archivo.\n";
    exit(1);
  }
  file >> rows_ >> columns_;
  Resize_(rows_, columns_);
  std::string line;
  int row{0};
  char cell;
  while (std::getline(file, line)) {
    for (size_t i{0}; i < line.size(); ++i) {
      cell = line[i];
      if (cell == 'X') {
        cells_[row][i].SetState(State::alive);
      } else {
        cells_[row][i].SetState(State::dead);
      }
    }
    row++;
  }
}

Cell& Lattice::GetCell(const Position& position) {
  if (position.first < 0 || position.first >= rows_ || position.second < 0 || position.second >= columns_) {
    if (frontier_type_ == open_cold) {
      return frontier_cell_;
    } else if (frontier_type_ == open_hot) {
      frontier_cell_.SetState(State::alive);
      return frontier_cell_;
    } else if (frontier_type_ == periodic) {
      int row = position.first;
      int column = position.second;
      if (row < 0) {
        row = rows_ - abs(row);
      } else if (row >= rows_) {
        row = row - rows_;
      }
      if (column < 0) {
        column = columns_ - abs(column);
      } else if (column >= columns_) {
        column = column - columns_;
      }
      return cells_[row][column];
    } else if (frontier_type_ == reflexed) {
      int row = position.first;
      int column = position.second;
      if (row < 0) {
        row = abs(row);
      } else if (row >= rows_) {
        row = rows_ - (row - rows_);
      }
      if (column < 0) {
        column = abs(column);
      } else if (column >= columns_) {
        column = columns_ - (column - columns_);
      }
      return cells_[row][column];
    } else if (frontier_type_ == no_frontier) {
      return frontier_cell_;
    }
  }
  return cells_[position.first][position.second];
}

Cell& Lattice::operator[](const Position& position) {
  return GetCell(position);
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  std::cout << "Población: " << lattice.Population() << '\n';
  std::cout << "Tamaño: " << lattice.rows_ << "x" << lattice.columns_ << '\n';
  for (int i{0}; i < lattice.rows_; ++i) {
    for (int j{0}; j < lattice.columns_; ++j) {
      os << lattice.cells_[i][j];
    }
    os << '\n';
  }
  return os;
}

Neighbourhood Lattice::GetNeighbourhood(const Position& position) {
  int row = position.first;
  int column = position.second;
  Cell up_left = GetCell(Position(row - 1, column - 1));
  Cell up = GetCell(Position(row - 1, column));
  Cell up_right = GetCell(Position(row - 1, column + 1));
  Cell left = GetCell(Position(row, column - 1));
  Cell right = GetCell(Position(row, column + 1));
  Cell down_left = GetCell(Position(row + 1, column - 1));
  Cell down = GetCell(Position(row + 1, column));
  Cell down_right = GetCell(Position(row + 1, column + 1));
  return Neighbourhood(up_left, up, up_right, left, right, down_left, down, down_right);
}

void Lattice::NextGeneration() {
  if (frontier_type_ == no_frontier) {
    FrontierExpansion();
  }
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < columns_; ++j) {
      cells_[i][j].NextState(*this);
    }
  }
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < columns_; ++j) {
      cells_[i][j].UpdateState();
    }
  }
}

void Lattice::FrontierExpansion() {
  bool top{false}, bottom{false}, left{false}, right{false};
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < columns_; ++j) {
      if (i == 0 && cells_[i][j].GetState() == State::alive) {
        top = true;
      }
      if (i == rows_ - 1 && cells_[i][j].GetState() == State::alive) {
        bottom = true;
      }
      if (j == 0 && cells_[i][j].GetState() == State::alive) {
        left = true;
      }
      if (j == columns_ - 1 && cells_[i][j].GetState() == State::alive) {
        right = true;
      }
    }
  }
  if (top) {
    cells_.insert(cells_.begin(), std::vector<Cell>(columns_));
    ++rows_;
  }
  if (bottom) {
    cells_.push_back(std::vector<Cell>(columns_));
    ++rows_;
  }
  if (left) {
    for (int i{0}; i < rows_; ++i) {
      cells_[i].insert(cells_[i].begin(), Cell(State::dead));
    }
    ++columns_;
  }
  if (right) {
    for (int i{0}; i < rows_; ++i) {
      cells_[i].push_back(Cell(State::dead));
    }
    ++columns_;
  }
  Resize_(rows_, columns_);
}

void Lattice::Resize_(int rows, int columns) {
  rows_ = rows;
  columns_ = columns;
  cells_.resize(rows_);
  for (int i{0}; i < rows_; ++i) {
    cells_[i].resize(columns_);
    for (int j{0}; j < columns_; ++j) {
      cells_[i][j].SetIndex(Position(i, j));
    }
  }
}

size_t Lattice::Population() const {
  size_t population = 0;
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < columns_; ++j) {
      if (cells_[i][j].GetState() == State::alive) {
        ++population;
      }
    }
  }
  return population;
}

void Lattice::SetCells_() {
  char answer;
  do {
    std::cout << "Quieres cambiar el estado de alguna célula? (s/n): \n";
    do {
      std::cin >> answer;
    } while (answer != 's' && answer != 'n');
    if (answer == 's') {
      std::cout << "Introduce la fila y la columna de la célula que quieres cambiar: \n";
      int row, column;
      std::cin >> row >> column;
      GetCell(Position(row, column)).SetState(State::alive);
    }
  } while (answer == 's');
}
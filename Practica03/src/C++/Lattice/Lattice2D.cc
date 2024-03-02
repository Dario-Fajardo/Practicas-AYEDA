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

/**
 * @brief Constructor de la clase Lattice2D
 * @param size tamaño del retículo
 * @param factory fábrica de células
 * @param rows número de filas
 * @param columns número de columnas
 */
Lattice2D::Lattice2D(const size_t size, const FactoryCell& factory, const int& rows, const int& columns) : Lattice(size, factory, 2, rows, columns) {
  for (int i = 0; i < rows; i++) {
    std::vector<Cell*> row;
    for (int j = 0; j < columns; j++) {
      row.push_back(unidimensional_lattice_[i * columns + j]);
    }
    bidimensional_lattice_.push_back(row);
  }
}

/**
 * @brief Constructor de la clase Lattice2D a partir de un fichero que permite modificar el estado de las células
 * @param filename nombre del archivo
 * @param factory fábrica de células
 */
Lattice2D::Lattice2D(const char* filename, const FactoryCell& factory) : Lattice(filename, factory) {
  for (size_t i = 0; i < rows_; i++) {
    std::vector<Cell*> row;
    for (size_t j = 0; j < columns_; j++) {
      row.push_back(unidimensional_lattice_[i * columns_ + j]);
    }
    bidimensional_lattice_.push_back(row);
  }
}

/**
 * @brief Método que devuelve la vecindad de una célula en el retículo
 * @param position posición de la célula
 * @param mode modo de vecindad
 * @return vecindad de la célula
 */
Neighbourhood Lattice2D::GetNeighbours(const Position& position, const int& mode) const {
  Neighbourhood neighbours;
  if (mode == 0) {
    PositionDim<2> left = {position[0], position[1] - 1};
    PositionDim<2> right = {position[0], position[1] + 1};
    neighbours = Neighbourhood{GetCell(left).GetState(), GetCell(right).GetState(), State::Dead, State::Dead, State::Dead, State::Dead, State::Dead, State::Dead};
  } else {
    PositionDim<2> up_left = {position[0] - 1, position[1] - 1};
    PositionDim<2> up = {position[0] - 1, position[1]};
    PositionDim<2> up_right = {position[0] - 1, position[1] + 1};
    PositionDim<2> left = {position[0], position[1] - 1};
    PositionDim<2> right = {position[0], position[1] + 1};
    PositionDim<2> down_left = {position[0] + 1, position[1] - 1};
    PositionDim<2> down = {position[0] + 1, position[1]};
    PositionDim<2> down_right = {position[0] + 1, position[1] + 1};
    neighbours = Neighbourhood{GetCell(up_left).GetState(), GetCell(up).GetState(), GetCell(up_right).GetState(), GetCell(left).GetState(), GetCell(right).GetState(), GetCell(down_left).GetState(), GetCell(down).GetState(), GetCell(down_right).GetState()};
  }
  return neighbours;
}

/**
 * @brief Método que avanza una generación en el retículo
 */
void Lattice2D::NextGeneration() {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      int first = i;
      int second = j;
      PositionDim<2> position = {first, second};
      GetCell(position).NextState(*this);
    }
  }
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      int first = i;
      int second = j;
      PositionDim<2> position = {first, second};
      GetCell(position).UpdateState();
    }
  }
}

/**
 * @brief Método que devuelve el número de células vivas en el retículo
 * @return población del retículo
 */
size_t Lattice2D::Population() const {
  size_t population = 0;
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      int first = i;
      int second = j;
      PositionDim<2> position = {first, second};
      if (GetCell(position).GetState() == State::Alive) {
        population++;
      }
    }
  }
  return population;
}

/**
 * @brief Método que muestra el retículo por pantalla
 * @param os flujo de salida
 * @return flujo de salida
 */
std::ostream& Lattice2D::Display(std::ostream& os) const {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < columns_; j++) {
      int first = i;
      int second = j;
      PositionDim<2> position = {first, second};
      os << GetCell(position).GetState() << " ";
    }
    os << std::endl;
  }
  return os;
}
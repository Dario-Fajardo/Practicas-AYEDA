/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abtracta Lattice1D. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional.
 */
#include "Lattice1D.h"

Lattice1D::Lattice1D(const size_t& size, const FactoryCell& factory) : Lattice(size, factory) {
  lattice_.resize(size_);
  for (size_t i = 0; i < size_; i++) {
    Position* position = new PositionDim<1>(1, i);
    lattice_[i] = factory_.CreateCell(*position, State::Dead);
  }
}

Lattice1D::Lattice1D(const char* file_name, const FactoryCell& factory) : Lattice(0, factory) {
  std::ifstream file(file_name, std::ios_base::in);
  if (!file.is_open()) {
    std::cerr << "Error: file could not be opened." << std::endl;
    exit(1);
  }
  file >> size_;
  lattice_.resize(size_);
  std::string line;
  for (size_t i = 0; i < size_; i++) {
    Position* position = new PositionDim<1>(1, i);
    lattice_[i] = factory_.CreateCell(*position, State::Dead);
  }
  while (getline(file, line)) {
    for (size_t i{0}; i < line.size(); ++i) {
      char cell{line[i]};
      if (cell == 'X') {
        lattice_[i]->SetState(State::Alive);
      } else {
        lattice_[i]->SetState(State::Dead);
      }
    }
  }
  file.close();
}

Neighbourhood Lattice1D::GetNeighbours(const Position& position, const int& mode) const {
  Neighbourhood neighbours;
  if (mode == 0) {
    size_t left = (position[0] - 1);
    size_t right = (position[0] + 1);
    neighbours = Neighbourhood{GetCell(PositionDim<1>{1, left}).GetState(), GetCell(PositionDim<1>{1, right}).GetState(), State::Dead, State::Dead, State::Dead, State::Dead, State::Dead, State::Dead};
  } else {
    std::cerr << "[DEBUG]: Modo no válido" << std::endl;
    exit(1);
  }
  return neighbours;
}

void Lattice1D::NextGeneration() {
  for (size_t i = 0; i < size_; i++) {
    lattice_[i]->NextState(*this);
  }
  for (size_t i = 0; i < size_; i++) {
    lattice_[i]->UpdateState();
  }
}

size_t Lattice1D::Population() const {
  size_t population = 0;
  for (size_t i = 0; i < size_; i++) {
    if (lattice_[i]->GetState() == State::Alive) {
      population++;
    }
  }
  return population;
}

std::ostream& Lattice1D::Display(std::ostream& os) const {
  for (size_t i = 0; i < size_; i++) {
    os << *lattice_[i] << " ";
  }
  return os;
}
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 14 Feb 2024
 * @brief En este archivo se define la clase Lattice. Que imlementa el comportamiento del retículo en un autómata celular.
 */
#include "../include/lattice.h"
#include "../include/cell.h"

Lattice::Lattice(const int& size, const Frontier& frontier_type) {
  size_ = size;
  frontier_type_ = frontier_type;
  cells_ = new Cell[size];
  for (int i = 0; i < size; i++) {
    if (i == floor(size / 2)) {
      cells_[i] = Cell(i, State::one);
    } else {
      cells_[i] = Cell(i, State::zero);
    }
  }
}

Lattice::~Lattice() {
  delete[] cells_;
}

Cell Lattice::GetCell(const Position& position) const {
  return cells_[position];
}

Frontier Lattice::GetFrontierType() const {
  return frontier_type_;
}

int Lattice::GetSize() const {
  return size_;
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.size_; i++) {
    os << lattice.cells_[i];
  }
  return os;
}

void Lattice::NextGeneration() {
  for (int i = 0; i < size_; i++) {
    cells_[i].NextState(*this);
  }
  for (int i = 0; i < size_; i++) {
    cells_[i].UpdateState();
  }
}
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se define la clase Célula. Que implementa el comportamiento de una célula en un autómata celular.
 */
#include "../include/cell.h"
#include "../include/lattice.h"

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  char state = cell.GetState() == State::zero ? '0' : '1';
  os << state;
  return os;
}

void Cell::TransitionFunction_(const State& left, const State& right) {
  int value = (state_ + right + state_ * right + left * state_ * right) % 2;
  next_state_ = value == 1 ? State::one : State::zero;
}

void Cell::NextState(const Lattice& lattice) {
  Position left = index_ - 1;
  Position right = index_ + 1;
  if (left < 0) {
    switch (lattice.GetFrontierType()) {
      case Frontier::periodic:
        left = lattice.GetSize() - 1;
        break;
      case Frontier::fixed_hot:
        left = 1;
        break;
      case Frontier::fixed_cold:
        left = 0;
        break;
    }
  }
  if (right >= lattice.GetSize()) {
    switch (lattice.GetFrontierType()) {
      case Frontier::periodic:
        right = lattice.GetCell(0).GetIndex();
        break;
      case Frontier::fixed_hot:
        right = 1;
        break;
      case Frontier::fixed_cold:
        right = 0;
        break;
    }
  }
  TransitionFunction_(lattice.GetCell(left).GetState(), lattice.GetCell(right).GetState());
}

void Cell::UpdateState() {
  state_ = next_state_;
}
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 23 Feb 2024
 * @brief En este archivo se declara la clase Célula. Que define el comportamiento de una célula en un autómata celular.
 */
#include "../include/cell.h"
#include "../include/lattice.h"

/**
 * @brief Sobrecarga del operador << para la clase Cell
 * 
 * @param os: flujo de salida
 * @param cell: célula a imprimir
 * 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.GetState() == State::alive) {
    os << "X";
  } else {
    os << " ";
  }
  return os;
}

void Cell::NextState(Lattice& lattice) {
  TransitionFunction_(lattice.GetNeighbourhood(index_));
}

void Cell::UpdateState() {
  state_ = next_state_;
}

void Cell::TransitionFunction_(const Neighbourhood& neighbourhood) {
  int alive = CheckNeibourhood_(neighbourhood);
  if (state_ == State::alive) {
    if (alive < 2 || alive > 3) {
      next_state_ = State::dead;
    } else {
      next_state_ = State::alive;
    }
  } else if (state_ == State::dead) {
    if (alive == 3) {
      next_state_ = State::alive;
    } else {
      next_state_ = State::dead;
    }
  }
}

int Cell::CheckNeibourhood_(const Neighbourhood& neighbourhood) {
  int alive = 0;
  if (std::get<0>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<1>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<2>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<3>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<4>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<5>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<6>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  if (std::get<7>(neighbourhood).GetState() == State::alive) {
    ++alive;
  }
  return alive;
}
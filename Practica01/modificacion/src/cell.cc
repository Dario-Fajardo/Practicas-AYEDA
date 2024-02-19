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

/**
 * @brief Sobrecarga del operador de salida para imprimir una célula.
 * 
 * @param os Flujo de salida.
 * @param cell Célula a imprimir.
 * 
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  char state = cell.GetState() == State::zero ? ' ' : 'X';
  os << state;
  return os;
}

/**
 * @brief Función de transición de estado de la célula.
 * 
 * @param left Estado de la célula izquierda.
 * @param right Estado de la célula derecha. 
 */
void Cell::TransitionFunction_(const State& left, const State& right, const State& three_from_center) {
  int value = (state_ + right + state_ * right + left * state_ * right + three_from_center) % 2;
  next_state_ = value == 1 ? State::one : State::zero;
}

/**
 * @brief Calcula el siguiente estado de la célula.
 * 
 * @param lattice Lattice al que pertenece la célula.
 */
void Cell::NextState(const Lattice& lattice) {
  Position left = index_ - 1;
  Position right = index_ + 1;
  Position three_from_center = index_ + 3;
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
  if (three_from_center >= lattice.GetSize()) {
    switch (lattice.GetFrontierType()) {
      case Frontier::periodic:
        three_from_center = lattice.GetCell(three_from_center % lattice.GetSize()).GetIndex();
        break;
      case Frontier::fixed_hot:
        three_from_center = 1;
        break;
      case Frontier::fixed_cold:
        three_from_center = 0;
        break;
    }
  }
  TransitionFunction_(lattice.GetCell(left).GetState(), lattice.GetCell(right).GetState(), lattice.GetCell(three_from_center).GetState());
}

/**
 * @brief Actualiza el estado de la célula al siguiente estado. Usado para sincronizar los estados de todas las células en su lattice.
 */
void Cell::UpdateState() {
  state_ = next_state_;
}
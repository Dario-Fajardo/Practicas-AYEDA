/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se define la clase Célula. Que define el comportamiento de una célula en un autómata celular.
 */
#include "../include/cell.h"

Cell::Cell() {
  state_ = State::zero;
  index_ = 0;
}

void Cell::TransitionFunction_(const State& left, const State& right) {
  int value = (state_ + right + state_ * right + left * state_ * right) % 2;
  next_state_ = value == 1 ? State::one : State::zero;
}

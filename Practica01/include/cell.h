/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se declara la clase Célula. Que define el comportamiento de una célula en un autómata celular.
 */
#ifndef CELL_H
#define CELL_H

#include <iostream>
#include "lattice.h"

typedef int Position;

enum State : int {
  zero = 0,
  one = 1
};

class Cell {
 public:
  // Constructores y destructor
  Cell();
  Cell(const Position& position, const State& state) : index_(position), state_(state) {}
  // Getters
  inline State GetState() const { return state_; }
  // Setters
  inline void SetState(const State& state) { state_ = state; }
  // Operadores
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
  // Métodos
  void NextState(const Lattice& lattice);
  void UpdateState(const State& left, const State& center, const State& right);
 private:
  State state_;
  Position index_;
  State next_state_;
  void TransitionFunction_(const State& left, const State& right);
};

#endif
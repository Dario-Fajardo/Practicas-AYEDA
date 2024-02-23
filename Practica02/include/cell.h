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
#include <tuple>
#include "types.h"

class Lattice;

class Cell {
 public:
  // Constructores y destructor
  Cell() : index_(0, 0), state_(State::dead) {};
  Cell(const Position& position, const State& state) : index_(position), state_(state) {}
  Cell(const State& state) : state_(state) {}
  // Getters
  inline State GetState() const { return state_; }
  inline Position GetIndex() const { return index_; }
  // Setters
  inline void SetState(const State& state) { state_ = state; }
  inline void SetIndex(const Position& index) { index_ = index; }
  // Operadores
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
  // Métodos
  void NextState(Lattice& lattice);
  void UpdateState();
 private:
  Position index_;
  State state_;
  State next_state_;
  void TransitionFunction_(const Neighbourhood& neighbourhood);
  int CheckNeibourhood_(const Neighbourhood& neighbourhood);
};

#endif
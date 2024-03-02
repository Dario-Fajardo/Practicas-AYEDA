/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta Cell. Que define como e implementarán las células en un autómata celular general.
 */
#ifndef CELL_H
#define CELL_H

#include "../Position/Position.h"
#include "../Types/Types.h" 
#include <iostream>

class Lattice;

class Cell {
 public:
  // Constructores
  Cell() = default;
  Cell(const Position& position, const State& state) : position_{const_cast<Position&>(position)}, state_{state} {}
  // Getters
  State GetState() const { return state_; }
  Position& GetPosition() const { return position_; }
  // Setters
  void SetState(const State& state) { state_ = state; }
  void SetPosition(const Position& position) { position_ = const_cast<Position&>(position); }
  // Otros métodos
  virtual void NextState(const Lattice& lattice) = 0;
  virtual void UpdateState() = 0;
  friend std::ostream& operator<<(std::ostream& output, const Cell& cell);
 protected:
  Position& position_;
  State state_;
  State next_state_;
  virtual std::ostream& Display_(std::ostream& ouput) const = 0;
};

#endif  // CELL_H
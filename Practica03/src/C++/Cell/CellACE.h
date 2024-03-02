/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase CellACE, que hereda de la clase Cell. Define cómo se implementarán las células en un autómata celular elemental.
 */
#ifndef CELL_ACE_H
#define CELL_ACE_H

#include "Cell.h"

class CellACE : public Cell {
 public:
  // Constructores
  CellACE() = default;
  CellACE(const Position& position, const State& state) : Cell(position, state) {};
  // Otros métodos
  void NextState(const Lattice& lattice) override;
  void UpdateState() override { state_ = next_state_; };
 protected:
  virtual void TransitionFunction_(const State& left, const State& Right) = 0;
  std::ostream& Display_(std::ostream& output) const override;
};

#endif // CELL_ACE_H
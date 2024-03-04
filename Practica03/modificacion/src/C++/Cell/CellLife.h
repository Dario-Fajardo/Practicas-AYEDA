/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase CellLife, que hereda de la clase Cell. Define cómo se implementarán las células en el juego de la vida.
 */
#ifndef CELL_LIFE_H
#define CELL_LIFE_H

#include "Cell.h"

class CellLife : public Cell {
 public:
  // Constructores
  CellLife() = default;
  CellLife(const Position& position, const State& state) : Cell(position, state) {};
  // Otros métodos
  void NextState(const Lattice& lattice) override;
  void UpdateState() override { state_ = next_state_; };
 protected:
  std::ostream& Display_(std::ostream& output) const override;
  virtual void TransitionFunction_(const Neighbourhood& neighbours) = 0;
  int AliveNeighbours_(const Neighbourhood& neighbours);
};

#endif
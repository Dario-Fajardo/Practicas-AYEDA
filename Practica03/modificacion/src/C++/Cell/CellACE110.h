/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase CellACE110, que hereda de la clase CellACE. Define cómo se implementarán 
 *        las células en un autómata celular elemental con la regla 110.
 */
#ifndef CELL_ACE110_H
#define CELL_ACE110_H

#include "CellACE.h"

class CellACE110 : public CellACE {
 public:
  // Constructores
  CellACE110() = default;
  CellACE110(const Position& position, const State& state) : CellACE(position, state) { position_ = const_cast<Position&>(position); }
  // Otros métodos
  void TransitionFunction_(const State& left, const State& right) override;
};

#endif // CELL_ACE110_H
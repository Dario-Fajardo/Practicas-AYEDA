/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase CellLife23_3 que hereda de la clase CellLife. Define cómo se implementarán 
 *        las células en el juego de la vida con la regla 23/3.
 */
#ifndef CELL_LIFE23_3_H
#define CELL_LIFE23_3_H

#include "CellLife.h"

class CellLife23_3 : public CellLife {
 public:
  // Constructores
  CellLife23_3() = default;
  CellLife23_3(const Position& position, const State& state) : CellLife(position, state) {};
  // Otros métodos
  void TransitionFunction_(const Neighbourhood& neighbours) override;
};

#endif // CELL_LIFE23_3_H
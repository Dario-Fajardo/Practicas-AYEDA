/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase CellLife51_346 que hereda de la clase CellLife. Define cómo se implementarán 
 *        las células en el juego de la vida con la regla 51/346.
 */
#ifndef CELL_LIFE51_346_H
#define CELL_LIFE51_346_H

#include "CellLife.h"

class CellLife51_346 : public CellLife {
 public:
  // Constructores
  CellLife51_346() = default;
  CellLife51_346(const Position& position, const State& state) : CellLife(position, state) {};
  // Otros métodos
  void TransitionFunction_(const Neighbourhood& neighbours) override;
};

#endif // CELL_LIFE51_346_H
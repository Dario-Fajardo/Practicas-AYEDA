/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase CellLife51_346 que hereda de la clase CellLife. Define cómo se implementarán 
 *        las células en el juego de la vida con la regla 51/346.
 */
#include "CellLife51_346.h"

/**
 * @brief Método que calcula el siguiente estado de la célula en el juego de la vida con la regla 51/346.
 * @param neighbours Vecindad de la célula.
 */
void CellLife51_346::TransitionFunction_(const Neighbourhood& neighbours) {
  int alive_neighbours = AliveNeighbours_(neighbours);
  if (state_ == State::Alive) {
    if (alive_neighbours == 5 || alive_neighbours == 1) {
      next_state_ = State::Alive;
    } else {
      next_state_ = State::Dead;
    }
  } else {
    if (alive_neighbours == 3 || alive_neighbours == 4 || alive_neighbours == 6) {
      next_state_ = State::Alive;
    } else {
      next_state_ = State::Dead;
    }
  }
}
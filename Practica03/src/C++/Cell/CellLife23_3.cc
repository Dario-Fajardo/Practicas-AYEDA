/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase CellLife23_3 que hereda de la clase CellLife. Define cómo se implementarán 
 *        las células en el juego de la vida con la regla 23/3.
 */
#include "CellLife23_3.h"

/**
 * @brief Método que calcula el siguiente estado de la célula en el juego de la vida con la regla 23/3.
 * @param neighbours Vecindad de la célula.
 */
void CellLife23_3::TransitionFunction_(const Neighbourhood& neighbours) {
int alive_neighbours = AliveNeighbours_(neighbours);
  if (state_ == State::Alive) {
    if (alive_neighbours < 2 || alive_neighbours > 3) {
      next_state_ = State::Dead;
    } else {
      next_state_ = State::Alive;
    }
  } else {
    if (alive_neighbours == 3) {
      next_state_ = State::Alive;
    } else {
      next_state_ = State::Dead;
    }
  }
  
}
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase CellLife, que hereda de la clase Cell. Define cómo se implementarán las células en el juego de la vida.
 */
#include "CellLife.h"
#include "../Lattice/Lattice.h"

/**
 * @brief Método que calcula el siguiente estado de la célula en el juego de la vida.
 * @param lattice Retículo que contiene la célula.
 */
void CellLife::NextState(const Lattice& lattice) {
  Neighbourhood neighbours = lattice.GetNeighbours(position_, 1);
  TransitionFunction_(neighbours);
}

/**
 * @brief Método que peermite mostrar el estado de la célula en la consola.
 * @param output Flujo de salida.
 * 
 * @return std::ostream& Flujo de salida.
 */
std::ostream& CellLife::Display_(std::ostream& output) const {
  output << (state_ == State::Dead ? " " : "X");
  return output;
}

int CellLife::AliveNeighbours_(const Neighbourhood& neighbours) {
  int alive_neighbours = 0;
  if (std::get<0>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<1>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<2>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<3>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<4>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<5>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<6>(neighbours) == State::Alive) alive_neighbours++;
  if (std::get<7>(neighbours) == State::Alive) alive_neighbours++;
  return alive_neighbours;
}
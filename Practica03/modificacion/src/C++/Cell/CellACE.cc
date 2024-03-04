/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase CellACE, que hereda de la clase Cell. Define cómo se implementarán las células en un autómata celular elemental.
 */
#include "CellACE.h"
#include "../Lattice/Lattice.h"

/**
 * @brief Método que calcula el siguiente estado de la célula usando la función de transición.
 * @param lattice Retículo que contiene la célula.
 */
void CellACE::NextState(const Lattice& lattice) {
  Neighbourhood neighbours = lattice.GetNeighbours(position_, 0);
  TransitionFunction_(std::get<0>(neighbours), std::get<1>(neighbours));
}

/**
 * @brief Método que peermite mostrar el estado de la célula en la consola.
 * @param output Flujo de salida.
 * 
 * @return std::ostream& Flujo de salida.
 */
std::ostream& CellACE::Display_(std::ostream& output) const {
  output << (state_ == State::Dead ? " " : "X");
  return output;
}
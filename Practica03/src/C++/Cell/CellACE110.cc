/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase CellACE110, que hereda de la clase CellACE. Define cómo se implementarán 
 *        las células en un autómata celular elemental con la regla 110.
 */
#include "CellACE110.h"

/**
 * @brief Método que calcula el siguiente estado de la célula en el autómata celular elemental con la regla 110.
 * @param lattice Retículo que contiene la célula.
 */
void CellACE110::TransitionFunction_(const State& left, const State& right) {
  int value = (state_ + right + state_ * right + left * state_ * right) % 2;
  next_state_ = value == 1? State::Alive : State::Dead;
}
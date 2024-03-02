/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase CellACE30, que hereda de la clase CellACE. Define cómo se implementarán 
 *        las células en un autómata celular elemental con la regla 30.
 */
#include "CellACE30.h"

/**
 * @brief Función de transición de estado para la regla 30.
 * @param left Estado de la célula izquierda.
 * @param right Estado de la célula derecha.
 */
void CellACE30::TransitionFunction_(const State& left, const State& right) {
  int value = (left + state_ + right + state_ * right) % 2;
  next_state_ = value == 1? State::Alive : State::Dead;
}
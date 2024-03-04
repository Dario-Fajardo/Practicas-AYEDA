/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declaran algunos tipos de datos que se usarán en el programa.
 */
#ifndef TYPES_H
#define TYPES_H

#include <tuple>

enum State : int {
  Dead = 0,
  Alive = 1
};

typedef std::tuple<State, State, State, State, State, State, State, State> Neighbourhood; 

#endif  // TYPES_H
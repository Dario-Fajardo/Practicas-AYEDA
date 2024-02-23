/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 22 Feb 2024
 * @brief En este archivo se definen tipos que se usarán en el resto del programa.
 */

#ifndef TYPES_H
#define TYPES_H

#include <utility>

class Cell;

typedef std::pair<int, int> Position;

enum State : int {
  dead = 0,
  alive = 1
};

enum Frontier : int {
  periodic = 0,
  open_hot = 1,
  open_cold = 2,
  reflexed = 3, 
  no_frontier = 4
};

typedef std::tuple<Cell, Cell, Cell, Cell, Cell, Cell, Cell, Cell> Neighbourhood;


#endif
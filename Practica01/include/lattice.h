/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se define la clase Lattice. Que define el comportamiento del retículo en un autómata celular.
 */
#ifndef LATTICE_H
#define LATTICE_H

#include <iostream>
#include "cell.h"

enum class Frontier : int {
  periodic = 0,
  fixed_hot = 1,
  fixed_cold = 2
};

class Lattice {
 public:
  // Constructores y destructor
  Lattice();
  Lattice(const int& size, const Frontier& frontier_type);
  ~Lattice() { delete[] cells_; }
  // Getters
  const inline Cell GetCell(const Position& position) const { return cells_[position]; }
  const inline Frontier GetFrontierType() const { return frontier_type_; }
  // Operadores
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);
  // Métodos
  void NextGeneration();
 private:
  Cell *cells_;
  Frontier frontier_type_;
};

#endif
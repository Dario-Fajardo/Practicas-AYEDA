/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se define la clase Lattice. Que imlementa el comportamiento del retículo en un autómata celular.
 */
#ifndef LATTICE_H
#define LATTICE_H

#include <iostream>
#include <cmath>
#include <vector>
#include "types.h"

class Cell;

class Lattice {
 public:
  // Constructores y destructor
  Lattice() : rows_(0), columns_(0), frontier_type_(Frontier::periodic) {};
  Lattice(int rows, int columns, Frontier frontier_type);
  Lattice(const char* filename);
  ~Lattice();
  // Getters
  Cell GetCell(const Position& position) const;
  Frontier GetFrontierType() const;
  int GetSize() const;
  // Operadores
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);
  Cell& operator[](const Position& position) const;
  // Métodos
  void NextGeneration();
  size_t Population() const;
 private:
  std::vector<std::vector<Cell>> cells_;
  int rows_;
  int columns_;
  Frontier frontier_type_;
};

#endif
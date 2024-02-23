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
#include <fstream>
#include "types.h"
#include "cell.h"

class Cell;

class Lattice {
 public:
  // Constructores y destructor
  static Lattice CreateLattice(const Position& size, Frontier frontier_type, const char* input_file);
  Lattice() : rows_(0), columns_(0), frontier_type_(Frontier::periodic) {};
  Lattice(int rows, int columns, Frontier frontier_type);
  Lattice(const char* filename, Frontier frontier_type);
  // Getters
  Cell& GetCell(const Position& position);
  Frontier GetFrontierType() const { return frontier_type_; };
  Position GetSize() const { return Position(rows_, columns_); };
  Neighbourhood GetNeighbourhood(const Position& position);
  // Operadores
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);
  Cell& operator[](const Position& position);
  // Métodos
  void NextGeneration();
  size_t Population() const;
  void FrontierExpansion();
 private:
  void SetCells_();
  void Resize_(int rows, int columns);
  std::vector<std::vector<Cell>> cells_;
  int rows_;
  int columns_;
  Frontier frontier_type_;
  Cell frontier_cell_;
};

#endif
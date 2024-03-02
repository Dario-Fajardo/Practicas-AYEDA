/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta Lattice. Que define como se 
 *        implementará el retículo en un autómata celular general.
 */
#ifndef LATTICE_H
#define LATTICE_H

#include "../Types/Types.h"
#include "../FactoryCell/FactoryCell.h"
#include "../Position/PositionDim.h"
#include <fstream>
#include <vector>

class Cell;

class Lattice {
 public:
  // Constructores y destructor
  Lattice(const size_t size, const FactoryCell& factory, int dimensions, size_t rows = 0, size_t columns = 0);
  Lattice(const char* filename, const FactoryCell& factory);
  // virtual ~Lattice();
  // Getters
  virtual Cell& GetCell(const Position& position) const = 0;
  virtual Neighbourhood GetNeighbours(const Position& position, const int& mode) const = 0;
  // Operadores
  virtual Cell& operator[](const Position& position) const = 0;
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);
  // Otros métodos
  virtual void NextGeneration() = 0;
  virtual size_t Population() const = 0;
  virtual std::ostream& Display(std::ostream& os) const = 0;
 protected:
  size_t size_;
  size_t rows_;
  size_t columns_;
  std::vector<Cell*> unidimensional_lattice_;
  FactoryCell& factory_;
};

#endif  // LATTICE_H
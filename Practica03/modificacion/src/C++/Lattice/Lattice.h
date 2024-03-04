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
  // Constructores
  Lattice(const size_t size, const FactoryCell& factory) : size_(size), factory_(const_cast<FactoryCell&>(factory)) {};
  virtual ~Lattice() {};
  // Getters
  virtual Cell& GetCell(const Position& position) const = 0;
  virtual Neighbourhood GetNeighbours(const Position& position, const int& mode) const = 0;
  std::pair<size_t, size_t> GetDimensions() const { return std::make_pair(size_, size_); }
  // Operadores
  virtual Cell& operator[](const Position& position) const = 0;
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);
  // Otros métodos
  virtual void NextGeneration() = 0;
  virtual size_t Population() const = 0;
  virtual std::ostream& Display(std::ostream& os) const = 0;
 protected:
  size_t size_;
  FactoryCell& factory_;
};


#endif
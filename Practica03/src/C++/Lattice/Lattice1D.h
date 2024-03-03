/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abtracta Lattice1D. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional.
 */
#ifndef LATTICE1D_H
#define LATTICE1D_H

#include "Lattice.h"

class Lattice1D : public Lattice {
 public:
  // Constructores
  Lattice1D(const size_t& size, const FactoryCell& factory);
  Lattice1D(const char* file_name, const FactoryCell& factory);
  // Getters
  Cell& GetCell(const Position& position) const = 0;
  Neighbourhood GetNeighbours(const Position& position, const int& mode) const override;
  // Operadores
  Cell& operator[](const Position& position) const = 0;
  // Otros métodos
  void NextGeneration() override;
  size_t Population() const override;
  std::ostream& Display(std::ostream& os) const override;
 protected:
  std::vector<Cell*> lattice_;
};

#endif
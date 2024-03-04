/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta Lattice2DReflective. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser bidimenstional y con forntera reflectiva.
 */
#ifndef LATTICE2D_NOBORDER_H
#define LATTICE2D_NOBORDER_H

#include "Lattice2D.h"
#include <cmath>

class Lattice2DNoBorder : public Lattice2D {
 public:
  // Constructores y destructor
  Lattice2DNoBorder(const size_t size, const FactoryCell& factory, const size_t& rows, const size_t& columns);
  Lattice2DNoBorder(const char* filename, const FactoryCell& factory) : Lattice2D(filename, factory) {};
  // Getters
  Cell& GetCell(const Position& position) const override;
  Cell& GetCell(const Position& position);
  std::pair<size_t, size_t> GetDimensions() const { return std::make_pair(rows_, columns_); }
  // Operadores
  Cell& operator[](const Position& position) const override;
  // Otros métodos
  void NextGeneration() override;
  void FrontierExpansion();
  private:
  void Resize_(size_t rows, size_t columns);
};

#endif // LATTICE2D_NOBORDER_H
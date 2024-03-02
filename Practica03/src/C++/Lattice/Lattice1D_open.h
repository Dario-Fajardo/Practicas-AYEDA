/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta Lattice1DOpen. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional y con forntera abierta.
 */
#ifndef LATTICE1D_OPEN_H
#define LATTICE1D_OPEN_H

#include "Lattice1D.h"

enum OpenType : int {
  Cold = 0,
  Hot = 1
};

class Lattice1DOpen : public Lattice1D {
 public:
  // Constructores y destructor
  Lattice1DOpen(const size_t size, const FactoryCell& factory, OpenType open_type) : Lattice1D(size, factory), open_type_(open_type) {};
  Lattice1DOpen(const char* filename, const FactoryCell& factory, OpenType open_type): Lattice1D(filename, factory), open_type_(open_type) {};
  ~Lattice1DOpen();
  // Getters
  Cell& GetCell(const Position& position) const override;
  // Operadores
  Cell& operator[](const Position& position) const override;
 private:
  OpenType open_type_;
};

#endif
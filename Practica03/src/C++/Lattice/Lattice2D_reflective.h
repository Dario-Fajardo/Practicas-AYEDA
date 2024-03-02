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
#ifndef LATTICE2D_REFLECTIVE_H
#define LATTICE2D_REFLECTIVE_H

#include "Lattice2D.h"
#include <cmath>

class Lattice2DReflective : public Lattice2D {
 public:
  // Constructores y destructor
  Lattice2DReflective(const size_t size, const FactoryCell& factory, const int& rows, const int& columns) : Lattice2D(size, factory, rows, columns) {};
  Lattice2DReflective(const char* filename, const FactoryCell& factory) : Lattice2D(filename, factory) {};
  ~Lattice2DReflective();
  // Getters
  Cell& GetCell(const Position& position) const override;
  // Operadores
  Cell& operator[](const Position& position) const override;
};

#endif // LATTICE2D_REFLECTIVE_H
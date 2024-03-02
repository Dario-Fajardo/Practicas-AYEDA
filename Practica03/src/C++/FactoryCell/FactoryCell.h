/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta FactoryCell. Que se usa para que la clase 
 *        Lattice sepa que tipo de células debe crear.
 */
#ifndef FACTORYCELL_H
#define FACTORYCELL_H

#include "../Cell/Cell.h"

class FactoryCell {
 public:
  virtual Cell* CreateCell(const Position& position, const State& state) const = 0;
};

#endif
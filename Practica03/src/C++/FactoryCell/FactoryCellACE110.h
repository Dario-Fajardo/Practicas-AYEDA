/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase FactoryCellACE100. Que crea células de tipo CellACE100.
 */
#ifndef FACTORYCELLACE110_H
#define FACTORYCELLACE110_H

#include "FactoryCell.h"
#include "../Cell/CellACE110.h"

class FactoryCellACE110 : public FactoryCell {
 public:
  virtual Cell* CreateCell(const Position& position, const State& state) const override { return new CellACE110(position, state); }
};

#endif // FACTORYCELLACE110_H
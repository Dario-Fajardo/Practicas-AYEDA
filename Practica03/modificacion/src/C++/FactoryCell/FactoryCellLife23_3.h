/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase FactoryCellLife23_3. Que crea células de tipo CellLife23_3.
 */
#ifndef FACTORYCELLACE23_3_H
#define FACTORYCELLACE23_3_H

#include "FactoryCell.h"
#include "../Cell/CellLife23_3.h"

class FactoryCellLife23_3 : public FactoryCell {
 public:
  virtual Cell* CreateCell(const Position& position, const State& state) const override { return new CellLife23_3(position, state); }
};

#endif // FACTORYCELLACE23_3_H
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se encuentra la función main del programa.
 */
#include "Position/PositionDim.h"
#include "Cell/CellACE110.h"
#include "Cell/CellACE30.h"
#include "Cell/CellLife23_3.h"
#include "Cell/CellLife51_346.h"
#include "Lattice/Lattice1D_periodic.h"
#include "FactoryCell/FactoryCellACE110.h"
#include <iostream>

int main(int argc, char* argv[]) {
  FactoryCellACE100 factory;
  Lattice1DPeriodic lattice(10, factory);
  for (int i = 0; i < 10; i++) {
    std::cout << lattice << std::endl;
    lattice.NextGeneration();
  }
  return 0;
}
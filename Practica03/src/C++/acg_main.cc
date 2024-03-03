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
#include "FactoryCell/FactoryCellACE110.h"
#include "FactoryCell/FactoryCellACE30.h"
#include "FactoryCell/FactoryCellLife23_3.h"
#include "FactoryCell/FactoryCellLife51_346.h"
#include "Lattice/Lattice1D_periodic.h"
#include "Lattice/Lattice1D_open.h"
#include "Lattice/Lattice2D_reflective.h"
#include "Lattice/Lattice2D_noborder.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  FactoryCellLife23_3 factory;
  Lattice2DNoBorder lattice{"confs/Espiral.conf", factory};
  system("clear");
  for (size_t i = 0; i < 200; i++) {
    std::cout << lattice << std::endl;
    lattice.FrontierExpansion();
    lattice.NextGeneration();
    system("sleep 0.02");
    system("clear");
  }
}
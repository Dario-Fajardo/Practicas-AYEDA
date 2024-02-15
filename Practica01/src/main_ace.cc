/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief Arrchivo main del programa que simula un autómata celular elemental.
 */
#include "../include/lattice.h"
#include "../include/cell.h" 
#include <ncurses.h>

int main(int argc, char* argv[]) {
  Lattice lattice(200, Frontier::periodic);
  std::cout << lattice << std::endl;
  for (int i = 0; i < 400; ++i) {
    lattice.NextGeneration();
    std::cout << lattice << std::endl;
  }
}
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta Lattice1DPeriodic. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional y con forntera periódica.
 */
#ifndef LATTICE1D_PERIODIC_H
#define LATTICE1D_PERIODIC_H

#include "Lattice1D.h"

class Lattice1DPeriodic : public Lattice1D {
 public:
  // Constructores y destructor
  Lattice1DPeriodic(const size_t size, const FactoryCell& factory) : Lattice1D(size, factory) {
    std::cout << "Quieres cambiar el tamaño del retículo? (s/n)" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 's') {
      std::cout << "Introduce la posición de la célula que quieres cambiar" << std::endl;
      size_t position;
      std::cin >> position;
      unidimensional_lattice_[position]->SetState(State::Alive);
    }
  };
  Lattice1DPeriodic(const char* filename, const FactoryCell& factory) : Lattice1D(filename, factory) {};
  // ~Lattice1DPeriodic();
  // Getters
  Cell& GetCell(const Position& position) const override;
  // Operadores
  Cell& operator[](const Position& position) const override;
};

#endif // LATTICE1D_PERIODIC_H
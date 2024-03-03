/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se deefine la clase abstracta Lattice1DOpen. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional y con forntera abierta.
 */
#include "Lattice1D_open.h"

Lattice1DOpen::Lattice1DOpen(const size_t size, const FactoryCell& factory, OpenType open_type) : Lattice1D(size, factory), open_type_(open_type) {
  char answer{'s'};
  do {
    std::cout << "Quieres poner alguna célula en estado viva? (s/n)" << std::endl;
    do {
      std::cin >> answer;
    } while (answer != 's' && answer != 'n');
    if (answer == 's') {
      size_t position;
      do {
        std::cout << "Introduce la posición de la célula que quieres poner en estado viva: ";
        std::cin >> position;
      } while (position < 0 || position >= size);
      lattice_[position]->SetState(State::Alive);
    }
  } while(answer == 's'); 
}

/**
 * @brief Método que devuelve la célula en la posición dada
 * @param position posición de la célula
 * 
 * @return Célula en la posición dada 
 */
Cell& Lattice1DOpen::GetCell(const Position& position) const {
  if (position[0] < 0 || static_cast<size_t>(position[0]) >= lattice_.size()) {
    State state = open_type_ == OpenType::Cold ? State::Dead : State::Alive;
    Position* position_cell = new PositionDim<1>(1, position[0]);
    return *factory_.CreateCell(*position_cell, state);
  }
  return *lattice_[position[0]];
}

/**
 * @brief Sobrecarga del operador [] para acceder a una célula en cierta posición del retículo
 * @param position posición de la célula 
 */
Cell& Lattice1DOpen::operator[](const Position& position) const {
  return GetCell(position);
}
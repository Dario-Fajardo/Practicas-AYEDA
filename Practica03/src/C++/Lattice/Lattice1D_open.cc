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

/**
 * @brief Constructor de la clase Lattice1DOpen 
 */
Lattice1DOpen::~Lattice1DOpen() {
  for (size_t i = 0; i < unidimensional_lattice_.size(); i++) {
    delete unidimensional_lattice_[i];
  }
  unidimensional_lattice_.~vector();
}

/**
 * @brief Método que devuelve la célula en la posición dada
 * @param position posición de la célula
 * 
 * @return Célula en la posición dada 
 */
Cell& Lattice1DOpen::GetCell(const Position& position) const {
  if (position[0] < 0 || static_cast<size_t>(position[0]) >= unidimensional_lattice_.size()) {
    State state = open_type_ == OpenType::Cold ? State::Dead : State::Alive;
    return *factory_.CreateCell(position, state);
  }
  return *unidimensional_lattice_[position[0]];
}

/**
 * @brief Sobrecarga del operador [] para acceder a una célula en cierta posición del retículo
 * @param position posición de la célula 
 */
Cell& Lattice1DOpen::operator[](const Position& position) const {
  return GetCell(position);
}
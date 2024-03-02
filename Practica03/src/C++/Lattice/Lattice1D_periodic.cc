/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abstracta Lattice1DPeriodic. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional y con forntera periódica.
 */
#include "Lattice1D_periodic.h"

// /**
//  * @brief Destructor de la clase Lattice1DPeriodic 
//  */
// Lattice1DPeriodic::~Lattice1DPeriodic() {
//   for (size_t i = 0; i < unidimensional_lattice_.size(); i++) {
//     delete unidimensional_lattice_[i];
//   }
//   Lattice1D::~Lattice1D();
// }

/**
 * @brief Método que devuelve la célula en la posición dada
 * @param position posición de la célula
 * 
 * @return Célula en la posición dada 
 */
Cell& Lattice1DPeriodic::GetCell(const Position& position) const {
  if (position[0] < 0 || static_cast<size_t>(position[0]) >= unidimensional_lattice_.size()) {
    return *unidimensional_lattice_[position[0] % unidimensional_lattice_.size()];
  }
  return *unidimensional_lattice_[position[0]];
}

/**
 * @brief Sobrecarga del operador [] para acceder a una célula en cierta posición del retículo
 * @param position posición de la célula 
 */
Cell& Lattice1DPeriodic::operator[](const Position& position) const {
  return GetCell(position);
}
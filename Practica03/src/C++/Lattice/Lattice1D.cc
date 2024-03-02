/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abtracta Lattice1D. Que define como se 
 *        implementará el retículo en un autómata celular general en caso de ser unidimensional.
 */
#include "Lattice1D.h"

// /**
//  * @brief Destructor de la clase Lattice1D 
//  */
// Lattice1D::~Lattice1D() {
//   Lattice::~Lattice();
// }

/**
 * @brief Método que devuelve la vecindad de una célula en la posición dada
 * @param position Posición de la célula
 * @param mode Modo de vecindad (ACE[0] o Life[1], en este caso solo se implementa el modo 0 ya que no se puede implementar el juego de la vida con un
 *             retículo unidimensional) 
 * 
 * @return Vecindad de la célula
 */
Neighbourhood Lattice1D::GetNeighbours(const Position& position, const int& mode) const {
  Neighbourhood neighbours;
  if (mode == 0) {
    PositionDim<1> left{1, position[0] - 1};
    PositionDim<1> right{1, position[0] + 1};
    neighbours = Neighbourhood{GetCell(left).GetState(), GetCell(right).GetState(), State::Dead, State::Dead, State::Dead, State::Dead, State::Dead, State::Dead};
  } else {
    std::cerr << "[DEBUG]: Modo no válido" << std::endl;
    exit(1);
  }
  return neighbours;
}

/**
 * @brief Método que avanza una generación en el retículo
 */
void Lattice1D::NextGeneration() {
  for (size_t i = 0; i < size_; i++) {
    unidimensional_lattice_[i]->SetPosition(PositionDim<1>{1, i});
  }
  for (size_t i = 0; i < size_; i++) {
    std::cout << "Célula " << i << " en posición " << unidimensional_lattice_[i]->GetPosition()[0] << std::endl;
    unidimensional_lattice_[i]->NextState(*this);
  }
  for (size_t i = 0; i < size_; i++) {
    unidimensional_lattice_[i]->UpdateState();
  }
}

/**
 * @brief Método que devuelve la población del retículo
 * @return Población del retículo
 */
size_t Lattice1D::Population() const {
  size_t population = 0;
  for (size_t i = 0; i < size_; i++) {
    if (unidimensional_lattice_[i]->GetState() == State::Alive) {
      population++;
    }
  }
  return population;
}

/**
 * @brief Método que muestra el retículo por pantalla
 * @param os Flujo de salida
 * @return Flujo de salida
 */
std::ostream& Lattice1D::Display(std::ostream& os) const {
  for (size_t i = 0; i < size_; i++) {
    os << *unidimensional_lattice_[i];
  }
  return os;
}
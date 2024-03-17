/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 17 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase Sequence, 
 *        clase abstracta que se usara para implementar la tabla Hash.
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "../DispersionFunction/dispersion_function.h"
#include "../ExplorationFunction/exploration_function.h"
#include <cstddef>

template<class Key>
class Sequence {
 public:
  Sequence() = default;
  virtual bool Search(const Key&) const = 0;
  virtual bool Insert(const Key&) = 0; 
};

#endif  // SEQUENCE_H
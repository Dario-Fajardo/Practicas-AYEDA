/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta PositionDim. Que define como e implementarán las posiciones en un autómata celular
 *        dependiendo de sus dimensiones.
 */
#ifndef POSITIONDIM_H
#define POSITIONDIM_H

#include "Position.h"
#include <stdarg.h>

template <int Dim=2>
class PositionDim : public Position {
 public:
  PositionDim(int size, ...) {
    va_list args;
    va_start(args, size);
    for (int i{0}; i < Dim; i++) {
      coordinate_[i] = va_arg(args, coor_t);
    }
    va_end(args);
  }
  coor_t operator[](unsigned int index) const override { return coordinate_[index]; }
 private:
  coor_t coordinate_[Dim];
};

#endif  // POSITIONDIM_H
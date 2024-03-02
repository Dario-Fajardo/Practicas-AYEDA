/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declara la clase abstracta Position. Que define como e implementarán las posiciones en un autómata celular.
 */
#ifndef POSITION_H
#define POSITION_H

typedef int coor_t;

class Position {
 public:
  virtual coor_t operator[](unsigned int index) const = 0;
};

#endif  // POSITION_H
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se define la clase abstracta Lattice. Que define como se 
 *        implementará el retículo en un autómata celular general.
 */
#include "Lattice.h"
#include "../Cell/Cell.h"

/**
 * @brief Sobrecarga del operador de inserción para la clase Lattice.
 * @param os Flujo de salida.
 * @param lattice Lattice a mostrar.
 * 
 * @return std::ostream& Flujo de salida. 
 */
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  return lattice.Display(os);
}
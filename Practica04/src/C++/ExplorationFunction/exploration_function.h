/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 13 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase ExplorationFunction, clase abstracta y genérica padre que
 *        sirve para implementar una familia de clases utilizada para representar las distintas posibilidades de función 
 *        de exploración.
 */
#include "../DispersionFunction/dispersion_function.h"

template<class Key>
class ExplorationFunction {
 public:
  ExplorationFunction() = default;
  virtual unsigned operator(const Key&, unsigned) const = 0;
};
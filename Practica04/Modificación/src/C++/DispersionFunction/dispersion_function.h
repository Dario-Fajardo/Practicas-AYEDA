/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 13 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase DispersionFunction, clase abstracta y genérica padre que
 *        sirve para implementar una familia de clases utilizada para representar las distintas posibilidades de función 
 *        de dispersión
 */
#ifndef DISPERSION_FUNCTION_H
#define DISPERSION_FUNCTION_H

template<class Key>
class DispersionFunction {
 public:
  DispersionFunction() = default;
  virtual unsigned operator() (const Key&) const = 0;
  virtual unsigned GetTableSize() const = 0; 
};

#endif  // DISPERSION_FUNCTION_H
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 13 Mar 2024
 * @brief En este archivo se encuentra la función main del programa.
 */
#include<cstdlib>

class Nif {
 public:
  Nif() : nif_{rand()} {}
  Nif(unsigned nif) : nif_{nif} {}
  unsigned get_nif() const { return nif_; }
  operator long() const { return nif_; }
 private:
  long nif_;
};
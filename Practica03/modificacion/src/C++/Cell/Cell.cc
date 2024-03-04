/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se definen métodos de la clase abstracta Cell. Que define como e implementarán las células en un autómata celular general.
 */
#include "Cell.h"

/**
 * @brief Método que sobrecarga el operador de inserción para mostrar el estado de una célula.
 * @param output Flujo de salida.
 * @param cell Célula a mostrar.
 * 
 * @return std::ostream& Flujo de salida. 
 */
std::ostream& operator<<(std::ostream& output, const Cell& cell) {
  return cell.Display_(output);
}
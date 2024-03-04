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

#include <cstdarg>
#include <exception>
#include <string>
#include <iostream>

typedef int coor_t;

class Position {
 public:
  virtual ~Position() = default;
  virtual coor_t operator[](unsigned int index) const = 0;
};

class ac_exception : public std::exception {
 public:
  ac_exception(const std::string& message) : message_{message} {}
  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};

#endif  // POSITION_H
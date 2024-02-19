/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 1: Autómata Celular Elemental
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 9 Feb 2024
 * @brief En este archivo se declaran utilidades que se usarán en el resto del programa.
 */
#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <ctype.h>
#include <fstream>
#include "types.h"

int CheckParameters(const int argc, char *argv[], long unsigned int& size, Frontier& frontier_type, std::string& input_file);
void Usage(const bool mode);
bool IsDigit(const std::string& str);
std::string ExtractInitialConfiguration(const std::string& input_file);

#endif
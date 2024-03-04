/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se declaran diferentes herramientas que se utilizarán en el programa principal.
 */
#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>

int CheckParameters(bool& dim, bool& size, bool& init, bool& cell, bool& border, bool& help);
void Usage(const bool& help);
int ReadParameters(int argc, char* argv[], int& dim, std::vector<size_t>& size, char*& init, std::string& cell, std::string& border, bool& help);

#endif // TOOLS_H
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 13 Mar 2024
 * @brief En este archivo se encuentra la definición de la clase Nif, usada como Key en una tabla Hash.
 */
#include <string>
#include <iostream>

class Plate {
 public:
  Plate() = default;
  Plate(std::string plate, std::string brand = "none", std::string model = "sample",  int chasis_number = 0, int cc = 0) : letters_{plate.substr(0, 3)}, numbers_{std::stoi(plate.substr(3, 6))}, brand_{brand}, model_{model}, chasis_number_{chasis_number}, cc{cc} {};
  operator long() const;
  void operator=(const int numbers) { numbers_ = numbers; };
 private:
  std::string letters_;
  int numbers_;
  std::string brand_;
  std::string model_;
  int chasis_number_;
  int cc;
};

Plate::operator long() const {
  std::string letters_in_numbers;
  for (const auto& letter : letters_) {
    letters_in_numbers += std::to_string(static_cast<int>(letter));
  }
  std::string plate_string = letters_in_numbers + std::to_string(numbers_);
  return std::stol(plate_string);
}
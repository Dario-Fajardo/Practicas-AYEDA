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
#include<ctime>
#include<chrono>
#include<random>

class Nif {
 public:
  Nif() { GenerateNif(); }
  Nif(unsigned nif) : nif_{nif} {}
  unsigned GetNif() const { return nif_; }
  void SetNif(long nif) { nif_ = nif; }
  operator long() const { return nif_; }
  void GenerateNif();
 private:
  long nif_;
};

void Nif::GenerateNif() {
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(10000000, 99999999);
  nif_ = distribution(generator);
}
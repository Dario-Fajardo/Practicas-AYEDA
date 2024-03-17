/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 17 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase DynamicSequence
 *        usada para implementar la técnica de dispersion abierta
 */
#ifndef DYNAMIC_SEQUENCE_H
#define DYNAMIC_SEQUENCE_H

#include "sequence.h"
#include <vector>
#include <algorithm>

template<class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence() = default;
  bool Search(const Key& key) const override { return std::find(block_.begin(), block_.end(), key) != block_.end(); };
  bool Insert(const Key&) override;
 private:
  std::vector<Key> block_;
};

template<class Key>
bool DynamicSequence<Key>::Insert(const Key& key) {
  if (Search(key)) {
    return false;
  }
  block_.emplace_back(key);
  return true;
}

#endif // DYNAMIC_SEQUENCE_H
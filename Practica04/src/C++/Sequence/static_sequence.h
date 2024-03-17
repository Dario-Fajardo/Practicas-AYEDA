/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 17 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase StaticSequence
 *        usada para implementar la técnica de dispersion cerrada.
 */
#ifndef STATIC_SEQUENCE_H
#define STATIC_SEQUENCE_H

#include "sequence.h"

template<class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(const size_t block_size) : block_size_(block_size) { block_ = new Key[block_size]; } 
  bool Search(const Key&) const override;
  bool Insert(const Key&) override;
  bool IsFull() const;
 private:
  Key* block_;
  size_t block_size_;
};

template<class Key>
bool StaticSequence<Key>::Search(const Key& key) const {
  for (size_t i = 0; i < block_size_; ++i) {
    if (block_[i] == key) {
      return true;
    }
  }
  return false;
}

template<class Key>
bool StaticSequence<Key>::Insert(const Key& key) {
  if (IsFull()) {
    return false;
  }
  for (size_t i = 0; i < block_size_; ++i) {
    if (block_[i] == 0) {
      block_[i] = key;
      return true;
    }
  }
  return true;
}

template<class Key>
bool StaticSequence<Key>::IsFull() const {
  for (size_t i = 0; i < block_size_; ++i) {
    if (block_[i] == 0) {
      return false;
    }
  }
  return true;
}

#endif // STATIC_SEQUENCE_H
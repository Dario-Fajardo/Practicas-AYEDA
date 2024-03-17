/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 4: Búsqueda por dispersion
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 17 Mar 2024
 * @brief En este archivo se encuentra la declaración de la clase HashTable que
 *        implementa una tabla hash con cualquier tipo de dispersión.
 */
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../Sequence/dynamic_sequence.h"
#include "../Sequence/static_sequence.h"
#include "../Sequence/sequence.h"
#include <iostream>

template<class Key, class Container = StaticSequence<Key>>
class HashTable : public Sequence<Key> {
 public:
  HashTable(unsigned, unsigned, DispersionFunction<Key>&, ExplorationFunction<Key>&);
  bool Search(const Key&) const override;
  bool Insert(const Key&) override;
 private:
  unsigned table_size_;
  unsigned block_size_;
  Container** table_;
  DispersionFunction<Key>& fd_;
  ExplorationFunction<Key>& fe_;
};

template<class Key>
class HashTable<Key, DynamicSequence<Key>> : public Sequence<Key> {
 public:
  HashTable(unsigned, DispersionFunction<Key>&);
  bool Search(const Key&) const override;
  bool Insert(const Key&) override;
 private:
  unsigned table_size_;
  DynamicSequence<Key>* table_;
  DispersionFunction<Key>& fd_;
};

template<class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned table_size, unsigned block_size, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe) : table_size_{table_size}, block_size_{block_size}, fd_{fd}, fe_{fe} {
  table_ = new Container*[table_size_];
  for (unsigned i = 0; i < table_size_; ++i) {
    table_[i] = new Container(block_size_);
  }
}

template<class Key, class Container>
bool HashTable<Key, Container>::Search(const Key& key) const {
  unsigned index{fd_(key)};
  unsigned iteration{0};
  while (index < table_size_ && !table_[index]->Search(key)) {
    ++iteration;
    index += fe_(key, iteration);
  }
  if (index >= table_size_) {
    return false;
  }
  return true;
}

template<class Key, class Container>
bool HashTable<Key, Container>::Insert(const Key& key) {
  unsigned index{fd_(key)};
  unsigned iteration{0};
  while (index < table_size_ && !table_[index]->Insert(key)) {
    ++iteration;
    index += fe_(key, iteration);
  }
  if (index >= table_size_) {
    return false;
  }
  return true;
}

template<class Key>
HashTable<Key, DynamicSequence<Key>>::HashTable(unsigned table_size, DispersionFunction<Key>& fd) : table_size_{table_size}, fd_{fd} {
  table_ = new DynamicSequence<Key>[table_size_];
}

template<class Key>
bool HashTable<Key, DynamicSequence<Key>>::Search(const Key& key) const {
  unsigned index{fd_(key)};
  return table_[index].Search(key);
}

template<class Key>
bool HashTable<Key, DynamicSequence<Key>>::Insert(const Key& key) {
  unsigned index{fd_(key)};
  if (!table_[index].Insert(key)) {
    return false;
  }
  return true;
}

#endif // HASH_TABLE_H
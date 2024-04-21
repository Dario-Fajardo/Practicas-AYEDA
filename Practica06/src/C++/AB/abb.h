/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Implementación del TDA Árbol
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 21 Abr 2024
 * @brief En este archivo se encuentra la clase ABB, que representa un árbol binario de búsqueda. 
 */
#ifndef ABB_H
#define ABB_H

#include "ab.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  ABB() : AB<Key>() {};
  ABB(NodoB<Key>* root) : AB<Key>(root) {};

  bool Insert(const Key& key) override;
  bool Search(const Key& key) override;
};

template<class Key>
bool ABB<Key>::Insert(const Key& key) {
  NodoB<Key>* new_node = new NodoB<Key>(key);
  if (AB<Key>::GetRoot() == nullptr) {
    AB<Key>::SetRoot(new_node);
    return true;
  }

  NodoB<Key>* current = AB<Key>::GetRoot();
  NodoB<Key>* parent = nullptr;

  while (current != nullptr) {
    parent = current;
    if (long(key) < long(current->GetKey())) {
      current = current->GetLeft();
    } else if (long(key) > long(current->GetKey())) {
      current = current->GetRight();
    } else {
      return false;
    }
  }

  if (long(key) < parent->GetKey()) {
    parent->SetLeft(new_node);
  } else {
    parent->SetRight(new_node);
  }

  return true;
}

template<class Key>
bool ABB<Key>::Search(const Key& key) {
  NodoB<Key>* current = AB<Key>::GetRoot();

  while (current != nullptr) {
    if (long(key) < long(current->GetKey())) {
      current = current->GetLeft();
    } else if (long(key) > long(current->GetKey())) {
      current = current->GetRight();
    } else {
      return true;
    }
  }

  return false;
}

#endif // ABB_H
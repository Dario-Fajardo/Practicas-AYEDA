/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Implementación del TDA Árbol
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 21 Abr 2024
 * @brief En este archivo se encuentra la clase ABE, que representa un árbol binario balanceado. 
 */
#ifndef ABE_H
#define ABE_H

#include "ab.h"

template<class Key>
class ABE : public AB<Key> {
  public:
    ABE() : AB<Key>() {};
    bool Insert(const Key&) override;
    bool Search(const Key&) override;

    int Size(const NodoB<Key>* node) const {
      if (node == nullptr) return 0;
      return 1 + Size(node -> GetLeft()) + Size(node -> GetRight());
    }

  private:
    bool Insert(const Key&, NodoB<Key>* node);
    bool Search(const Key&, const NodoB<Key>*);
};

template<class Key>
bool ABE<Key>::Insert(const Key& key) {
  if (this -> GetRoot() == nullptr) {
    NodoB<Key>* newNodoB= new NodoB<Key> {key};
    this -> SetRoot(newNodoB);
    return true;
  }
  return Insert(key, this -> GetRoot());
}

template<class Key>
bool ABE<Key>::Search(const Key& key) {
  return Search(key, this -> GetRoot());
}

template<class Key>
bool ABE<Key>::Insert(const Key& key, NodoB<Key>* node) {
  if ( this -> Size(node -> GetLeft()) <= this -> Size(node -> GetRight())){
    if (node -> GetLeft() == nullptr) {
      NodoB<Key>* newNodoB= new NodoB<Key> {key};
      node->SetLeft(newNodoB);
      return true;
    }
    Insert(key, node -> GetLeft());
  } else {
    if (node -> GetRight() == nullptr) {
      NodoB<Key>* newNodoB= new NodoB<Key> {key};
      node -> SetRight(newNodoB);
      return true;
    }
    Insert(key, node -> GetRight());
  }
  return false;
}

template<class Key>
bool ABE<Key>::Search(const Key& key, const NodoB<Key>* node) {
  if (node == nullptr) return false;
  if (long(node -> GetKey()) == long(key)) return true;
  return (Search(key, node->GetLeft()) || Search(key, node->GetRight()));
}

#endif // ABE_H
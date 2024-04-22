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

  private:
    bool Insert(const Key&, NodoB<Key>* node);
    bool Search(const Key&, const NodoB<Key>*);
};

template<class Key>
bool ABE<Key>::Insert(const Key& key) {
  if (this -> getRoot() == nullptr) {
    NodoB<Key>* newNodoB= new NodoB<Key> {key};
    return this -> setRoot(newNodoB);
  }
  return Insert(key, this -> getRoot());
}

template<class Key>
bool ABE<Key>::Search(const Key& key) {
  return Search(key, this -> getRoot());
}

template<class Key>
bool ABE<Key>::Insert(const Key& key, NodoB<Key>* node) {
  if ( this -> Size(node -> getLeft()) <= this -> Size(node -> getRight())){
    if (node -> getLeft() == nullptr) {
      NodoB<Key>* newNodoB= new NodoB<Key> {key};
      node->setLeft(newNodoB);
      return true;
    }
    Insert(key, node -> getLeft());
  } else {
    if (node -> getRight() == nullptr) {
      NodoB<Key>* newNodoB= new NodoB<Key> {key};
      node -> setRight(newNodoB);
      return true;
    }
    Insert(key, node -> getRight());
  }
  return false;
}

template<class Key>
bool ABE<Key>::Search(const Key& key, const NodoB<Key>* node) {
  if (node == nullptr) return false;
  if (node -> getData() == key) return true;
  return (Search(key, node->getLeft()) || Search(key, node->getRight()));
}

#endif // ABE_H
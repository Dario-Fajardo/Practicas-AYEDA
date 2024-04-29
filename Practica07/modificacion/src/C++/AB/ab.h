/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Implementación del TDA Árbol
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 21 Abr 2024
 * @brief En este archivo se encuentra la clase AB, que representa un árbol binario. 
 */
#ifndef AB_H
#define AB_H

#include <iostream>
#include "../NodoB/nodob.h"

template<class Key>
class AB {
 public:
  AB() : root_{nullptr} {};
  AB(NodoB<Key>* root) : root_{root} {};

  NodoB<Key>* GetRoot() const { return root_; }
  void SetRoot(NodoB<Key>* root) { root_ = root; }

  virtual bool Insert(const Key& key) = 0;
  virtual bool Search(const Key& key) = 0;

  void InOrder(const NodoB<Key>* node);

 protected:
  NodoB<Key>* root_;
};

template<class Key>
void AB<Key>::InOrder(const NodoB<Key>* node) {
  if (node == nullptr) {
    return;
  }
  InOrder(node->GetLeft());
  std::cout << *node << " ";
  InOrder(node->GetRight());
}

#endif // AB_H
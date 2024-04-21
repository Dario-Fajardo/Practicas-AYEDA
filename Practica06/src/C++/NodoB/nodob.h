/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 5: Implementación del TDA Árbol
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 21 Abr 2024
 * @brief En este archivo se encuentra la clase NodoB, que representa un nodo de un árbol Binario.
 */
#ifndef NODOB_H
#define NODOB_H

#include <iostream>

template<class Key>
class NodoB {
 public:
  NodoB(Key key) : key_{key}, left_{nullptr}, right_{nullptr} {};
  NodoB(Key key, NodoB<Key>* left, NodoB<Key>* right) : key_{key}, left_{left}, right_{right} {};

  Key GetKey() const { return key_; }
  NodoB<Key>* GetLeft() const { return left_; }
  NodoB<Key>* GetRight() const { return right_; }

  void SetKey(Key key) { key_ = key; }
  void SetLeft(NodoB<Key>* left) { left_ = left; }
  void SetRight(NodoB<Key>* right) { right_ = right; }

  friend std::ostream& operator<<(std::ostream& os, const NodoB<Key>& nodo) {
    os << "[" << nodo.key_ << "]";
    return os;
  }
  
 private:
  Key key_;
  NodoB<Key>* left_;
  NodoB<Key>* right_;
};

#endif // NODOB_H
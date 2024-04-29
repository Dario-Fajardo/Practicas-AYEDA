/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 7: Implementación del TDA AVL
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 27 Abr 2024
 * @brief En este archivo se encuentra la clase NodoAVL, que representa los nodos de un AVL
 */
#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>

template<class Key>
class NodoAVL {
 public:
  NodoAVL(Key key) : key_{key}, left_{nullptr}, right_{nullptr} {};
  NodoAVL(Key key, NodoAVL<Key>* left, NodoAVL<Key>* right, int bal) : key_{key}, left_{left}, right_{right}, bal_{bal} {};

  Key GetKey() const { return key_; }
  NodoAVL<Key>* GetLeft() const { return left_; }
  NodoAVL<Key>* GetRight() const { return right_; }
  int GetBal() const { return bal_; }

  void SetKey(Key key) { key_ = key; }
  void SetLeft(NodoAVL<Key>* left) { left_ = left; }
  void SetRight(NodoAVL<Key>* right) { right_ = right; }
  void SetBal(int bal) { bal_ = bal; }

  friend std::ostream& operator<<(std::ostream& os, const NodoAVL<Key>& nodo) {
    os << "[" << nodo.key_ << "]";
    return os;
  }
  
 private:
  Key key_;
  NodoAVL<Key>* left_;
  NodoAVL<Key>* right_;
  int bal_;
};

#endif
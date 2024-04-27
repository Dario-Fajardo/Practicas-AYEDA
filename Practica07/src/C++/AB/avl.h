/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 7: Implementación del TDA AVL
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 27 Abr 2024
 * @brief En este archivo se encuentra la clase AVL
 */
#ifndef AVL_H
#define AVL_H

#include "abb.h"
#include "../NodoB/nodoavl.h"
#include <iostream>

template<class Key>
class AVL : public ABB<Key> {
 public:
  AVL() : ABB<Key>() {};
  AVL(NodoAVL<Key>* root) : ABB<Key>(root) {};

  bool Insert(const Key& key) override;

  void SetTraceMode(bool trace_mode) { trace_mode_ = trace_mode; }
 private:
  bool trace_mode_ = false;
  NodoAVL<Key>* root_;
  void IIRot(NodoAVL<Key>*& node);
  void DDRot(NodoAVL<Key>*& node);
  void IDRot(NodoAVL<Key>*& node);
  void DIRot(NodoAVL<Key>*& node);
  bool Insert(NodoAVL<Key>*& node, bool& grows, NodoAVL<Key>* aux);
  void InsertRebalanceLeft(NodoAVL<Key>*& node, bool& grows);
  void InsertRebalanceRight(NodoAVL<Key>*& node, bool& grows);
};

template<class Key>
void AVL<Key>::IIRot(NodoAVL<Key>*& node) {
  if (trace_mode_) {
    std::cout << "II rotation" << std::endl;
    std::cout << "Node: " << node->GetKey() << std::endl;
  }
  NodoAVL<Key>* aux = node->GetLeft();
  node->SetLeft(aux->GetRight());
  aux->SetRight(node);
  if (aux->GetBal() == 1) {
    node->SetBal(0);
    aux->SetBal(0);
  } else {
    node->SetBal(1);
    aux->SetBal(-1);
  }
  node = aux;
}

template<class Key>
void AVL<Key>::DDRot(NodoAVL<Key>*& node) {
  if (trace_mode_) {
    std::cout << "DD rotation" << std::endl;
    std::cout << "Node: " << node->GetKey() << std::endl;
  }
  NodoAVL<Key>* aux = node->GetRight();
  node->SetRight(aux->GetLeft());
  aux->SetLeft(node);
  if (aux->GetBal() == -1) {
    node->SetBal(0);
    aux->SetBal(0);
  } else {
    node->SetBal(-1);
    aux->SetBal(1);
  }
  node = aux;
}

template<class Key>
void AVL<Key>::IDRot(NodoAVL<Key>*& node) {
  if (trace_mode_) {
    std::cout << "ID rotation" << std::endl;
    std::cout << "Node: " << node->GetKey() << std::endl;
  }
  NodoAVL<Key>* aux1 = node->GetLeft();
  NodoAVL<Key>* aux2 = aux1->GetRight();
  node->SetLeft(aux2->GetRight());
  aux2->SetRight(node);
  aux1->SetRight(aux2->GetLeft());
  aux2->SetLeft(aux1);
  if (aux2->GetBal() == -1) {
    node->SetBal(1);
  } else {
    node->SetBal(0);
  }
  if (aux2->GetBal() == 1) {
    aux1->SetBal(-1);
  } else {
    aux1->SetBal(0);
  }
  aux2->SetBal(0);
  node = aux2;
}

template<class Key>
void AVL<Key>::DIRot(NodoAVL<Key>*& node) {
  if (trace_mode_) {
    std::cout << "DI rotation" << std::endl;
    std::cout << "Node: " << node->GetKey() << std::endl;
  }
  NodoAVL<Key>* aux1 = node->GetRight();
  NodoAVL<Key>* aux2 = aux1->GetLeft();
  node->SetRight(aux2->GetLeft());
  aux2->SetLeft(node);
  aux1->SetLeft(aux2->GetRight());
  aux2->SetRight(aux1);
  if (aux2->GetBal() == 1) {
    node->SetBal(-1);
  } else {
    node->SetBal(0);
  }
  if (aux2->GetBal() == -1) {
    aux1->SetBal(1);
  } else {
    aux1->SetBal(0);
  }
  aux2->SetBal(0);
  node = aux2;
}

template<class Key>
bool AVL<Key>::Insert(const Key& key) {
  NodoAVL<Key>* new_node = new NodoAVL<Key>(key, nullptr, nullptr, 0);
  bool grows = false;
  return Insert(this->root_, grows, new_node);
}

template<class Key>
bool AVL<Key>::Insert(NodoAVL<Key>*& node, bool& grows, NodoAVL<Key>* new_node) {
  if (node == nullptr) {
    node = new_node;
    grows = true;
  } else if (long(node->GetKey()) == long(new_node->GetKey())) {
    return false;
  } else if (long(new_node->GetKey()) < long(node->GetKey())) {
    NodoAVL<Key>* left = node->GetLeft();
    Insert(left, grows, new_node);
    if (grows) {
      InsertRebalanceLeft(node, grows);
    }
  } else {
    NodoAVL<Key>* right = node->GetRight();
    Insert(right, grows, new_node);
    if (grows) {
      InsertRebalanceRight(node, grows);
    }
  }
  return true;
}

template<class Key>
void AVL<Key>::InsertRebalanceLeft(NodoAVL<Key>*& node, bool& grows) {
  switch (node->GetBal()) {
    case -1:
      node->SetBal(0);
      grows = false;
      break;
    case 0:
      node->SetBal(1);
      break;
    case 1:
      NodoAVL<Key>* aux = node->GetLeft();
      if (aux->GetBal() == 1) {
        IIRot(node);
      } else {
        IDRot(node);
      }
      grows = false;
  }
}

template<class Key>
void AVL<Key>::InsertRebalanceRight(NodoAVL<Key>*& node, bool& grows) {
  switch (node->GetBal()) {
    case 1:
      node->SetBal(0);
      grows = false;
      break;
    case 0:
      node->SetBal(-1);
      break;
    case -1:
      NodoAVL<Key>* aux = node->GetRight();
      if (aux->GetBal() == -1) {
        DDRot(node);
      } else {
        DIRot(node);
      }
      grows = false;
  }
}

#endif // AVL_H
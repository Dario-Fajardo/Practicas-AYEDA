/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 7: Implementación del TDA AVL
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 27 Abr 2024
 * @brief Clase que representa personajes de D&D
 */
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

class Personaje {
 public:
  // Constructores
  Personaje() : nombre_{""}, clase_{""}, raza_{""}, alineamiento_{""}, nivel_{0}, puntos_de_vida_{0}, fuerza_{0}, destreza_{0}, constitucion_{0}, inteligencia_{0}, sabiduria_{0}, carisma_{0}, armadura_{0}, iniciativa_{0}, velocidad_{0} {};
  Personaje(std::string nombre, std::string clase, std::string raza, std::string alineamiento, int nivel, int puntos_de_vida, int fuerza, int destreza, int constitucion, int inteligencia, int sabiduria, int carisma, int armadura, int iniciativa, int velocidad) : nombre_{nombre}, clase_{clase}, raza_{raza}, alineamiento_{alineamiento}, nivel_{nivel}, puntos_de_vida_{puntos_de_vida}, fuerza_{fuerza}, destreza_{destreza}, constitucion_{constitucion}, inteligencia_{inteligencia}, sabiduria_{sabiduria}, carisma_{carisma}, armadura_{armadura}, iniciativa_{iniciativa}, velocidad_{velocidad} {};
  // Getters
  std::string GetNombre() const { return nombre_; }
  std::string GetClase() const { return clase_; }
  std::string GetRaza() const { return raza_; }
  std::string GetAlineamiento() const { return alineamiento_; }
  int GetNivel() const { return nivel_; }
  int GetPuntosDeVida() const { return puntos_de_vida_; }
  int GetPuntosDeVidaMaximos() const { return puntos_de_vida_maximos_; }
  int GetFuerza() const { return fuerza_; }
  int GetDestreza() const { return destreza_; }
  int GetConstitucion() const { return constitucion_; }
  int GetInteligencia() const { return inteligencia_; }
  int GetSabiduria() const { return sabiduria_; }
  int GetCarisma() const { return carisma_; }
  int GetArmadura() const { return armadura_; }
  int GetIniciativa() const { return iniciativa_; }
  int GetVelocidad() const { return velocidad_; }
  // Utilidades
  void Presentarse() const {
    std::cout << "Hola, soy " << nombre_ << ", un " << raza_ << " " << clase_ << " de alineamiento " << alineamiento_ << " de nivel " << nivel_ << "." << std::endl;
  }
  // Operadores
  friend std::ostream& operator<<(std::ostream& os, Personaje player);
  operator long() const;
 private:
  std::string nombre_;
  std::string clase_;
  std::string raza_;
  std::string alineamiento_;
  int nivel_;
  int puntos_de_vida_;
  int puntos_de_vida_maximos_;
  int fuerza_;
  int destreza_;
  int constitucion_;
  int inteligencia_;
  int sabiduria_;
  int carisma_;
  int armadura_;
  int iniciativa_;
  int velocidad_;
};

Personaje::operator long() const {
  int sum{nivel_ + puntos_de_vida_maximos_ + fuerza_ + destreza_ + constitucion_ + inteligencia_ + sabiduria_ + carisma_ + armadura_ + iniciativa_ + velocidad_};
  return sum / 11;
}

std::ostream& operator<<(std::ostream& os, Personaje player) {
  os << player.GetNombre();
  return os;
}

#endif
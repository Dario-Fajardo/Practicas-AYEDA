/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * 2º Curso en Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * Práctica 3: Autómata Celular General
 *
 * @author Dario Fajardo alu0101564630@ull.edu.es
 * @date 2 Mar 2024
 * @brief En este archivo se encuentra la función main del programa.
 */
#include "Position/PositionDim.h"
#include "Cell/CellACE110.h"
#include "Cell/CellACE30.h"
#include "Cell/CellLife23_3.h"
#include "Cell/CellLife51_346.h"
#include "FactoryCell/FactoryCell.h"
#include "FactoryCell/FactoryCellACE110.h"
#include "FactoryCell/FactoryCellACE30.h"
#include "FactoryCell/FactoryCellLife23_3.h"
#include "FactoryCell/FactoryCellLife51_346.h"
#include "Lattice/Lattice1D_periodic.h"
#include "Lattice/Lattice1D_open.h"
#include "Lattice/Lattice2D_reflective.h"
#include "Lattice/Lattice2D_noborder.h"
#include "Tools/Tools.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  int dim{0};
  std::vector<size_t> size;
  char* init{nullptr};
  std::string cell, border;
  bool help{false};
  int error_code = ReadParameters(argc, argv, dim, size, init, cell, border, help);
  if (error_code == 2) {
    return 0;
  } else if (error_code == 1) {
    return 1;
  }
  Lattice* lattice;
  FactoryCell* factory;
  if (init != nullptr) {
    if (cell == "ACE110") {
      factory = new FactoryCellACE110;
    } else if (cell == "ACE30") {
      factory = new FactoryCellACE30;
    } else if (cell == "Life23_3") {
      factory = new FactoryCellLife23_3;
    } else if (cell == "Life51_346") {
      factory = new FactoryCellLife51_346;
    }
    if (border == "periodic") {
      lattice = new Lattice1DPeriodic(init, *factory);
    } else if (border == "open cold") {
      lattice = new Lattice1DOpen(init, *factory, OpenType::Cold);
    } else if (border == "open hot") {
      lattice = new Lattice1DOpen(init, *factory, OpenType::Hot);
    } else if (border == "reflective") {
      lattice = new Lattice2DReflective(init, *factory);
    } else if (border == "noborder") {
      lattice = new Lattice2DNoBorder(init, *factory);
    }
  } else {
    if (cell == "ACE110") {
      factory = new FactoryCellACE110;
    } else if (cell == "ACE30") {
      factory = new FactoryCellACE30;
    } else if (cell == "Life23_3") {
      factory = new FactoryCellLife23_3;
    } else if (cell == "Life51_346") {
      factory = new FactoryCellLife51_346;
    }
    if (dim == 1) {
      if (border == "periodic") {
        lattice = new Lattice1DPeriodic(size[0], *factory);
      } else if (border == "open cold") {
        lattice = new Lattice1DOpen(size[0], *factory, OpenType::Cold);
      } else if (border == "open hot") {
        lattice = new Lattice1DOpen(size[0], *factory, OpenType::Hot);
      }
    } else if (dim == 2) {
      size_t total_size{size[0] * size[1]};
      if (border == "reflective") {
        lattice = new Lattice2DReflective(total_size, *factory, size[0], size[1]);
      } else if (border == "noborder") {
        lattice = new Lattice2DNoBorder(total_size, *factory, size[0], size[1]);
      }
    }
  }
  std::string options = "[x]: Salir del programa\n[n]: Generación siguiente\n[L]: Mostrar Y generaciones\n[c]: Alternar modo población\n[s]: Guardar en archivo\n";
  char option;
  bool poblation_flag{false};
  while (option != 'x') {
    if (poblation_flag) {
      std::cout << "Población: " << lattice->Population() << std::endl;
    } else {
      std::cout << *lattice << std::endl;
    }
    std::cout << options << std::endl;
    do {
      std::cout << "Introduzca una opción: \n";
      std::cin >> option;
    } while (option != 'x' && option != 'n' && option != 'L' && option != 'c' && option != 's');
    switch (option) {
      case 'x':
        system("clear");
        break;
      case 'n':
        lattice->NextGeneration();
        break;
      case 'L':
        int generations;
        do {
          std::cout << "Introduzca el número de generaciones a mostrar: ";
          std::cin >> generations;
        } while (generations < 0);
        for (int i{0}; i < generations; ++i) {
          lattice->NextGeneration();
          if (poblation_flag) {
            std::cout << "Población: " << lattice->Population() << std::endl;
          } else {
            std::cout << *lattice << std::endl;
          }
          system("sleep 0.05");
          system("clear");
        }
        break;
      case 'c':
        poblation_flag = !poblation_flag;
        break;
      case 's':
      {
        std::string filename;
        std::string dir{"saves/"};
        std::string extension{".sav"};
        std::cout << "Introduzca el nombre del archivo: ";
        std::cin >> filename;
        filename = dir + filename + extension;
        std::ofstream file(filename, std::ios_base::out);
        file << *lattice;
        file.close();
        break;
      }
    }
    system("clear");
  }
}
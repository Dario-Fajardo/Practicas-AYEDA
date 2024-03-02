# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# 2º Curso en Grado en Ingeniería Informática
# Algoritmos y Estructuras de Datos Avanzadas
# Practica 3: Autómata Celular General
#
# @author Dario Fajardo alu0101564630@ull.edu.es
# @date 2 Mar 2024
# @brief Makefile del proyecto, permite compilar facilmente y hacer make clean
#		 		 para borrar los binarios de la carpeta después

CXX = g++
CXXFLAGS = -Wall
######################################
files = src/C++/*/*cc
######################################
all: programa

programa: $(files)
	@echo "======================================================"
	@echo "chambeando..."
	@echo "======================================================"
	@$(CXX) $(CXXFLAGS) -o bin/acg $(files) src/C++/*cc

######################################
.PHONY: clean
######################################
clean:
	@echo "cleaning up the directory..."
	@rm bin/acg
######################################

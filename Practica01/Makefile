# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# 2º Curso en Grado en Ingeniería Informática
# Algoritmos y Estructuras de Datos Avanzadas
# Practica 1: Autómata Celular Elemental
#
# @author Dario Fajardo alu0101564630@ull.edu.es
# @date 9 Feb 2024
# @brief Makefile del proyecto, permite compilar facilmente y hacer make clean
#		 para borrar los binarios de la carpeta después

CXX = g++
CXXFLAGS = -Wall -lncurses
######################################
files = src/*cc
######################################
all: programa

programa: $(files)
	@echo "======================================================"
	@echo "chambeando..."
	@echo "======================================================"
	@$(CXX) $(CXXFLAGS) -o bin/ace-ayeda $(files)

######################################
.PHONY: clean
######################################
clean:
	@echo "cleaning up the directory..."
	@rm bin/ace-ayeda
######################################

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
BOLD_RED =\e[31m \e[1m
######################################
files = src/C++/*/*
######################################
all: programa

programa: $(files)
	@echo -e "$(BOLD_RED)======================================================"
	@echo -e "$(BOLD_RED)chambeando..."
	@echo -e "$(BOLD_RED)======================================================"
	@$(CXX) $(CXXFLAGS) -o bin/tda $(files) src/C++/*cc

######################################
.PHONY: clean
######################################
clean:
	@echo "cleaning up the directory..."
	@rm bin/tda
######################################
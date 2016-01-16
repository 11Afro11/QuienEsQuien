BIN 	= bin
SRC 	= src
OBJ 	= obj
LIB 	= lib
DOC 	= doc
INCLUDE = include

CXX = g++ -Ofast
CC = gcc -Ofast

LDFLAGS =
CPPFLAGS = -Wall -g -c

OBJECTS = test ConjuntoPreguntas ConjuntoPreguntas Pregunta Persona

all: preambulo $(OBJECTS)

$(OBJECTS):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cpp -I$(INCLUDE) $(LDFLAGS)

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo PRACTICA 2
	@echo
	@echo ESTRUCTURA DE DATOS
	@echo Grado en Ingenieria Informatica - Grupo C
	@echo
	@echo "("c")" FRANCISCO JAVIER FUENTES BARRAGAN Y SERGIO CARRASCO MARQUEZ
	@echo Escuela Tecnica Superior de Ingenieria Informatica y Telecomunicaciones
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo
#................................................

ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados:
	@echo
	@ls $(BIN)/

readme:
	@clear
	@echo
	@echo ------------------------------------------------------------
	@echo Compilacion Terminada
	@echo
	@echo Ejecutable Creado En /bin
	@echo 
	@echo Documentacion Creada en /doc en html y en Latex
	@echo 
	@echo Prara visualizar la documentacion: make open_doc
	@echo 
	@echo ------------------------------------------------------------
	@echo

# ************ Limpieza ************
clean:
	@-rm $(BIN)/* $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(DATOS)/*.aux $(DATOS)/*.log $(DATOS)/*.tex $(DATOS)/*.out $(DATOS)/*.tex ./Examen.pdf
	@-rm -rf $(DOC)/*
	@echo 
	@echo
	@echo Limpieza Terminada.
	@echo 

zip:
	zip -l $(NAME).zip  ./* src/*.cpp include/*.h datos/*.txt datos/*.jpg datos/* ./$(NAME).mak

doxygen:
	doxygen
open_doc:
	xdg-open ./doc/html/files.html

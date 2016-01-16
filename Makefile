

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include
DATOS = datos
DOC = doc

NAME = QuienEsQuien

all: clean preambulo ejecutables readme $(BIN)/test

##################################################################################
#Ejercicio 1
##################################################################################


$(BIN)/test: $(OBJ)/ConjuntoPersonas.o $(OBJ)/ConjuntoPreguntas.o $(OBJ)/test.o
	g++ -o $(BIN)/test $(OBJ)/test.o $(OBJ)/ConjuntoPreguntas.o &(OBJ)/ConjuntoPersonas.o


$(OBJ)/Pregunta.o: $(SRC)/Pregunta.cpp $(INCLUDE)/Pregunta.h
	g++ -c -g -o $(OBJ)/Pregunta.o $(SRC)/Pregunta.cpp -I$(INCLUDE)


$(OBJ)/ConjuntoPreguntas.o: $(SRC)/ConjuntoPreguntas.cpp $(INCLUDE)/ConjuntoPreguntas.h
	g++ -c -g -o $(OBJ)/ConjuntoPreguntas.o $(SRC)/ConjuntoPreguntas.cpp -I$(INCLUDE)

$(OBJ)/Persona.o: $(SRC)/Persona.cpp $(INCLUDE)/Persona.h
	g++ -c -g -o $(OBJ)/Persona.o $(SRC)/Persona.cpp -I$(INCLUDE)


$(OBJ)/ConjuntoPersonas.o: $(SRC)/ConjuntoPersonas.cpp $(INCLUDE)/ConjuntoPersonas.h
	g++ -c -g -o $(OBJ)/ConjuntoPersonas.o $(SRC)/ConjuntoPersonas.cpp -I$(INCLUDE)


$(OBJ)/test.o: $(SRC)/test.cpp $(INCLUDE)/ConjuntoPersonas.h $(INCLUDE)/ConjuntoPreguntas.h
	g++ -c -g -o $(OBJ)/test.o $(SRC)/test.cpp -I$(INCLUDE)

# $(OBJ)/PilaVector.o: $(SRC)/PilaVector.cpp $(INCLUDE)/PilaVector.h
# 	g++ -c -g -o $(OBJ)/PilaVector.o $(SRC)/PilaVector.cpp -I$(INCLUDE)


# $(OBJ)/PilaLista.o: $(SRC)/PilaLista.cpp $(INCLUDE)/PilaLista.h
# 	g++ -c -g -o $(OBJ)/PilaLista.o $(SRC)/PilaLista.cpp -I$(INCLUDE)

# $(OBJ)/PilaCola.o: $(SRC)/PilaCola.cpp $(INCLUDE)/PilaCola.h
# 	g++ -c -g -o $(OBJ)/PilaCola.o $(SRC)/PilaCola.cpp -I$(INCLUDE)

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo PRACTICA 2
	@echo
	@echo ESTRUCTURA DE DATOS
	@echo Grado en Ingenieria Informatica - Grupo C
	@echo
	@echo "("c")" FRANCISCO JAVIER FUENTES BARRAGAN
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

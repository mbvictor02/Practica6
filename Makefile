################################################################################
## Fichero «Makefile» para los programas de la práctica 6:
## «datos-pruebas», «contar-usos» y «usos-por-usuario»
################################################################################

datos-pruebas:                src/1-datos-pruebas.cpp | bin
	g++ -g -Wall -Wextra      src/1-datos-pruebas.cpp -o bin/datos-pruebas

contar-usos:                  build/2-contar-usos.o build/uso-bizi.o build/pedir-nombre-fichero.o  | bin
	g++ -g                    build/2-contar-usos.o build/uso-bizi.o build/pedir-nombre-fichero.o -o bin/contar-usos

usos-por-usuario:             
	echo Tienes que escribir las reglas para compilar el programa usos-por-usuario

build/2-contar-usos.o:        src/2-contar-usos.cpp src/uso-bizi.hpp src/pedir-nombre-fichero.hpp | build
	g++ -g -Wall -Wextra -c   src/2-contar-usos.cpp -o build/2-contar-usos.o 

build/pedir-nombre-fichero.o: src/pedir-nombre-fichero.cpp src/pedir-nombre-fichero.hpp | build
	g++ -g -Wall -Wextra -c   src/pedir-nombre-fichero.cpp -o build/pedir-nombre-fichero.o 

build/uso-bizi.o:             src/uso-bizi.cpp src/uso-bizi.hpp | build
	g++ -g -Wall -Wextra -c   src/uso-bizi.cpp -o build/uso-bizi.o 

bin:
	mkdir bin

build:
	mkdir build

clean:
ifeq ($(OS),Windows_NT)
	if exist bin rmdir /S /Q bin
	if exist build rmdir /S /Q build
else
	rm -f build/* bin/*
endif

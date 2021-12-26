# include <iostream>
# include <fstream>
# include <stdlib.h>
# include "uso-bizi.hpp"

bool leerUso(istream& f, UsoBizi& uso) {
    if (f.eof()) 
        return false;

    char tok[256];
    f.getline(tok, 256, ';'); uso.idUsuario = atoi(tok);
    f.getline(tok, 256, ';');
    f.getline(tok, 256, ';'); uso.estacionInicial = atoi(tok);
    f.getline(tok, 256, ';');
    f.getline(tok, 256, '\n'); uso.estacionFinal = atoi(tok);

    // devuelve true si alguna de las tres variables es != 0 -> comprueba que la última linea no es \n
    return uso.idUsuario || uso.estacionInicial || uso.estacionFinal;
}

bool contarUsos(const string rutaFichero, 
                unsigned& traslados, unsigned& usosCirculares) {
    ifstream f(rutaFichero);
    if (!f.is_open()) {
        cerr << "Error > no se pudo leer el fichero" << endl;
        return false;
    } 

    UsoBizi uso;
    leerUso(f, uso);
    while (leerUso(f, uso)) {
        if (uso.estacionInicial == uso.estacionFinal) usosCirculares += 1;
        else traslados += 1;
    }
    f.close();
    return true;
}
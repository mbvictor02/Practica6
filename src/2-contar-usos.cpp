#include <iostream>
#include "pedir-nombre-fichero.hpp"
#include "uso-bizi.hpp"

using namespace std;

int main () {
    string fichero;
    unsigned traslados  = 0, 
             circulares = 0;

    pedirNombreFichero(fichero);
    if (contarUsos(fichero, traslados, circulares)) {
        cout << "\nNúmero de usos como traslado: " << traslados;
        cout << "\nNúmero de usos circulares:    " << circulares;
        cout << "\nNúmero total de usos:         " << traslados + circulares;
        return 0;
    }    
    cerr << "Error > no se pudo contar los usos.";
    return 1;
}
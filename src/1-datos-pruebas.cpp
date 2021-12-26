#include <iostream>
#include <fstream>

using namespace std;

bool leerFichero(const string fichero, string v[], const int n)
{
    ifstream f(fichero);
    if (!f.is_open())
    {
        cerr << "error al abrir el fichero";
        return false;
    }

    getline(f, v[0]);
    for (int i = 1; i < n; i++)
    {
        getline(f, v[i]);
    }
    f.close();
    return true;
}

bool escribirFichero(const string fichero, const string v[], const int n)
{
    ofstream f(fichero);
    if (!f.is_open())
    {
        cerr << "error al crear el fichero";
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        f << v[i] << endl;
    }
    f.close();
    return true;
}

int main()
{
    int N1 = 10;
    string v1[N1];
    leerFichero("../datos/usos-16.csv", v1, N1);
    escribirFichero("../datos/pruebas-10.csv", v1, N1);

    int N2 = 2000;
    string v2[N2];
    leerFichero("../datos/usos-17.csv", v2, N2);
    escribirFichero("../datos/pruebas-2000.csv", v2, N2);

    return 0;
}
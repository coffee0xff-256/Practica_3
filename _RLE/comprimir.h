#ifndef COMPRIMIR_H
#define COMPRIMIR_H
#include <fstream>
#include <string>

using namespace std;
string comprimirRLE( string texto) {
    string resultado;
    int i = 0;
    int longitud = texto.length();

    while (i < longitud) {
        char actual = texto[i];
        int contador = 1;

        while (i + contador < longitud && texto[i + contador] == actual) {
            contador++;
        }

        resultado += actual;
        resultado += '[';
        resultado += to_string(contador);
        resultado += ']';

        i += contador;
    }

    return resultado;
}

#endif // COMPRIMIR_H

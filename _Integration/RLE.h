#ifndef RLE_H
#define RLE_H
#include <fstream>
#include <string>

using namespace std;

string comprimirRLE(string texto) {
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

void descomprimirRLE(string comprimido) {
    string resultado;
    int i = 0;
    int longitud = comprimido.length();
    ofstream out("descomprimidoRLE.txt");

    while (i < longitud) {
        char caracter = comprimido[i];
        i++;

        if (i < longitud && comprimido[i] == '[') {
            i++;

            string numeroStr;
            while (i < longitud && comprimido[i] >= '0' && comprimido[i] <= '9') {
                numeroStr += comprimido[i];
                i++;
            }

            if (i < longitud && comprimido[i] == ']') {
                i++;
            }

            int repeticiones = stoi(numeroStr);

            for (int j = 0; j < repeticiones; j++) {
                resultado += caracter;
            }
        }
    }

    out << resultado;
    out.close();
}

#endif // RLE_H

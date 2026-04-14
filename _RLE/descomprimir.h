#ifndef DESCOMPRIMIR_H
#define DESCOMPRIMIR_H
#include<iostream>
#include <string>
#include <fstream>
using namespace std;

string descomprimirRLE(string comprimido) {
    string resultado;
    int i = 0;
    int longitud = comprimido.length();

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

    return resultado;
}


bool verificar( string textoOriginal, string textoComprimido) {
    string textoDescomprimido = descomprimirRLE(textoComprimido);

    cout << "=== verificacion===" << endl;
    cout << "longitud original: " << textoOriginal.length() << " bytes" << endl;
    cout << "longitud comprimido: " << textoComprimido.length() << " bytes" << endl;
    cout << "longitud descomprimido: " << textoDescomprimido.length() << " bytes" << endl;
    cout << endl;

    cout << "texto original: \"" << textoOriginal << "\"" << endl;
    cout << "texto descomprimido: \"" << textoDescomprimido << "\"" << endl;
    cout << endl;

    if (textoOriginal == textoDescomprimido) {
        cout << "GOOD" << endl;
        return true;
    } else {
        cout << "BAD" << endl;
        return false;
    }
}


#endif // DESCOMPRIMIR_H

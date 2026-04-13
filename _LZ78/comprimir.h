#ifndef COMPRIMIR_H
#define COMPRIMIR_H
#include <fstream>
#include <iostream>
using namespace std;
void comprimirLZ78(const char* entrada, const char* salida)
{
    ifstream in(entrada);
    ofstream out(salida);

    char* texto = new char[1];
    int tam = 0;
    char c;
    while (in.get(c))
    {
        char* nuevo = new char[tam + 1];

        for (int i = 0; i < tam; i++)
            nuevo[i] = texto[i];

        nuevo[tam] = c;

        delete[] texto;
        texto = nuevo;

        tam++;
    }

    char** dic = new char*[tam];
    int dicSize = 0;
    int i = 0;

    while (i < tam)
    {
        int index = 0;
        int emparejamiento = -1;
        for (int j = 0; j < dicSize; j++)
        {
            int k = 0;
            while (dic[j][k] != '\0' && (i + k) < tam && texto[i + k] == dic[j][k])
                k++;
            if (dic[j][k] == '\0')
            {
                emparejamiento = j;
                index = k;
            }
        }

        char siguiente = (i + index < tam) ? texto[i + index] : '\0';

        if (emparejamiento == -1)
            out << 0 << "," << siguiente << "\n";
        else
            out << emparejamiento + 1 << "," << siguiente << "\n";
        int nuevoTam = index + 1;
        dic[dicSize] = new char[nuevoTam + 1];
        for (int k = 0; k < index; k++)
            dic[dicSize][k] = texto[i + k];
        dic[dicSize][index] = siguiente;
        dic[dicSize][nuevoTam] = '\0';

        dicSize++;

        i += nuevoTam;
    }

    for (int j = 0; j < dicSize; j++)
        delete[] dic[j];

    delete[] dic;
    delete[] texto;

    in.close();
    out.close();
}

#endif // COMPRIMIR_H

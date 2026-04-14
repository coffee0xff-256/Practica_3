#ifndef DESCOMPRIMIR_H
#define DESCOMPRIMIR_H

#include <fstream>
#include <iostream>
using namespace std;
void descomprimirLZ78(const char* entrada)
{
    ifstream in(entrada);
    ofstream out("descomprimido.txt");

    char** dic = new char*[1000];
    int dicSize = 0;

    int indice;
    char coma;
    char c;

    while (in >> indice >> coma)
    {

        in.get(c);

        int tamBase = 0;

        if (indice != 0)
        {
            while (dic[indice - 1][tamBase] != '\0')
                tamBase++;
        }

        char* nueva = new char[tamBase + 2];

        for (int i = 0; i < tamBase; i++){
            nueva[i] = dic[indice - 1][i];}

        nueva[tamBase] = c;
        nueva[tamBase + 1] = '\0';


        dic[dicSize] = nueva;
        dicSize++;

        for (int i = 0; nueva[i] != '\0'; i++){
            out << nueva[i];}

    }

    for (int i = 0; i < dicSize; i++){
        delete[] dic[i];}

    delete[] dic;

    in.close();
    out.close();
}

#endif
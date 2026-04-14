#ifndef LZ78_H
#define LZ78_H
#include <iostream>
#include <fstream>
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

        for (int i = 0; i < tam; i++){
            nuevo[i] = texto[i];}

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
        int lastMatch = -1;
        for (int j = 0; j < dicSize; j++)
        {
            int k = 0;
            while (dic[j][k] != '\0' && (i + k) < tam && texto[i + k] == dic[j][k]){
                k++;}
            if (dic[j][k] == '\0')
            {
                lastMatch = j;
                index = k;
            }
        }

        char siguiente = (i + index < tam) ? texto[i + index] : '\0';

        if (lastMatch == -1){
            out << 0 << "," << siguiente << "\n";}
        else{
            out << lastMatch + 1 << "," << siguiente << "\n";}

        int nuevoTam = index + 1;
        dic[dicSize] = new char[nuevoTam + 1];

        for (int k = 0; k < index; k++){
            dic[dicSize][k] = texto[i + k];}

        dic[dicSize][index] = siguiente;
        dic[dicSize][nuevoTam] = '\0';

        dicSize++;

        i += nuevoTam;
    }

    for (int j = 0; j < dicSize; j++){
        delete[] dic[j];}

    delete[] dic;
    delete[] texto;

    in.close();
    out.close();
}

void descomprimirLZ78(const char* entrada)
{
    ifstream in(entrada);
    ofstream out("descomprimidoLZ78.txt");

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
            while (dic[indice - 1][tamBase] != '\0'){
                tamBase++;}
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

#endif // LZ78_H

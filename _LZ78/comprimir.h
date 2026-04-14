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
    while (in.get(c))  // aqui leo lo que hay en el txt y lo paso a un arreglo dinamico tipo char
    {
        char* nuevo = new char[tam + 1];

        for (int i = 0; i < tam; i++){
            nuevo[i] = texto[i];}

        nuevo[tam] = c;

        delete[] texto;
        texto = nuevo;

        tam++;
    }
    // creacion del diccionario dinamico tipo python

    char** dic = new char*[tam]; // matriz dinamica similar a los diccionarios en python
    int dicsize = 0;
    int i = 0;

    while (i < tam)
    {
        int index = 0;
        int emparejamiento = -1;
        for (int j = 0; j < dicsize; j++)
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

        if (emparejamiento == -1){
            out << 0 << "," << siguiente << "\n";}
        else{
            out << emparejamiento + 1 << "," << siguiente << "\n";}


        int nuevoTam = index + 1;
        dic[dicsize] = new char[nuevoTam + 1];
        for (int k = 0; k < index; k++){
            dic[dicsize][k] = texto[i + k];}

        dic[dicsize][index] = siguiente;
        dic[dicsize][nuevoTam] = '\0';

        dicsize++;

        i += nuevoTam;
    }

    for (int j = 0; j < dicsize; j++){
        delete[] dic[j];}

    delete[] dic;
    delete[] texto;

    in.close();
    out.close();
}

#endif // COMPRIMIR_H

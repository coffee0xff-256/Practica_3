#ifndef ENCRIPTATIONLZ78_H
#define ENCRIPTATIONLZ78_H
#include <iostream>
#include <fstream>
using namespace std;

void encriptarlz78(const char* entrada, const char* salida, int n, unsigned char K)
{
    ifstream in(entrada);
    ofstream out(salida);

    char c;

    while (in.get(c))
    {
        unsigned char uc = (unsigned char)c;

        unsigned char rotado = (uc << n) | (uc >> (8 - n));

        unsigned char cifrado = rotado ^ K;

        out << (char)cifrado;
    }

    in.close();
    out.close();
}

void desencriptarlz78(const char* entrada, const char* salida, int n, unsigned char K)
{
    ifstream in(entrada);
    ofstream out(salida);

    char c;

    while (in.get(c))
    {
        unsigned char uc = (unsigned char)c;

        unsigned char xor_hecho = uc ^ K;

        unsigned char original = (xor_hecho >> n) | (xor_hecho << (8 - n));

        out << (char)original;
    }

    in.close();
    out.close();
}
#endif // ENCRIPTATIONLZ78_H
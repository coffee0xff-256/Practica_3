#include <iostream>
#include <comprimir.h>
#include <descomprimir.h>

using namespace std;
int main() {

    ifstream entrada("texto.txt");

    if (!entrada.is_open()) {
        cout << "error" << endl;
        return 1;
    }

    string textoOriginal;
    char c;

    while (entrada.get(c)) {
        textoOriginal += c;
    }
    entrada.close();

    cout << "=== archivo original ===" << endl;
    cout << "contenido: \"" << textoOriginal << "\"" << endl;
    cout << "longitud: " << textoOriginal.length() << " bytes" << endl;
    cout << endl;

    string textoComprimido = comprimirRLE(textoOriginal);

    cout << "=== texto comprimido ===" << endl;
    cout << "Contenido: " << textoComprimido << endl;
    cout << "Longitud: " << textoComprimido.length() << " bytes" << endl;
    cout << endl;

    ofstream salida("comprimido.txt");
    salida << textoComprimido;
    salida.close();
    verificar(textoOriginal, textoComprimido);

    return 0;
}
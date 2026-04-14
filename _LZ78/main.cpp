#include "comprimir.h"
#include "descomprimir.h"
bool comparararchivos(const char* txt1, const char* txt2)
{
    ifstream in1(txt1);
    ifstream in2(txt2);

    char c1, c2;
    bool soniguales = true;

    while (in1.get(c1) && in2.get(c2))
    {
        if (c1 != c2)
        {
            soniguales = false;
            break;
        }
    }

    in1.close();
    in2.close();

    if (soniguales)
    {
        cout << "descompresion y archivo original coinciden" << endl;
    }
    else
    {
        cout << "los archivos son diferentes" << endl;
    }

    return soniguales;
}

int main() {
    comprimirLZ78("original.txt","comprimido.txt");
    descomprimirLZ78("comprimido.txt");
    comparararchivos("original.txt","descomprimido.txt");
    return 0;
}
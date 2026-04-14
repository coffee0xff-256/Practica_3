#include <iostream>
#include <encriptation.h>
#include <desencriptation.h>

using namespace std;
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

int main()
{
    cout << "Hello World!" << endl;
    encriptar("comprimido.txt","encriptado.txt",7,6);
    desencriptar("encriptado.txt","desencriptado.txt",7,6);
    comparararchivos("comprimido.txt","desencriptado.txt");
    return 0;
}

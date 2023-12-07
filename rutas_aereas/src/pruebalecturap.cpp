#include "paises.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 1)
        cout << "Error. Los parametros son: paises.txt" << endl;

    Paises Pses;
    ifstream f(argv[1]);
    f>>Pses;
    cout<<Pses;
}
#include <iostream>

using namespace std;



void imprimirPiezas(unsigned short piezas[], int tam){
    for (int i =0; i<tam; i++){
        cout<<piezas[i]<<endl;
    }
}

int main()
{
    unsigned short piezas[7] = {
        0b0000111100000000,
        0b0110011000000000,
        0b0100111000000000,
        0b0110110000000000,
        0b1100011000000000,
        0b1000111000000000,
        0b0010111000000000
    };

    imprimirPiezas(piezas,7);

    return 0;
}


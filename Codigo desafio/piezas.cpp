#include <iostream>

using namespace std;


//Funcion para imprimir cada pieza en su representacion en binario y como una matriz 4*4

void piezasEnMatriz(unsigned short piezas){
    for(int fila = 0; fila<4 ; fila++){
        for (int col=0; col<4; col++){
            int bit = 15 - ((fila*4) + col);
            if ((piezas >> bit) & 1)
                cout<<"O";
            else
                cout<<".";
        }
        cout<<endl;
    }
    cout<<endl;
}


void imprimirPiezas(unsigned short piezas[], int tam){
    for (int i =0; i<tam; i++){
        piezasEnMatriz(piezas[i]);
    }
}

int main()
{
    unsigned short piezas[7] = {
        0b0000111100000000, // I
        0b0110011000000000, // O
        0b0100111000000000, // T
        0b0110110000000000, // S
        0b1100011000000000, // Z
        0b0100010011000000, // J
        0b1000100011000000 // L
    };

    imprimirPiezas(piezas,7);

    return 0;
}


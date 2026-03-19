#include <iostream>
#include "tablero.h"
using namespace std;


unsigned long long* CrearTablero(int alto){

    unsigned long long* tablero= new unsigned long long[alto];

    for(int i=0;i<alto;i++){
        tablero[i]=0ull;  // inicializar todo en 0
    }
    return tablero;
}

void DestruirTablero(unsigned long long* tablero){
    delete [] tablero;

}

int LimpiarFilas(unsigned long long* tablero, int alto, int ancho){

    unsigned long long mascara= 0ull;
    for(int i=0; i< ancho; i++){
        mascara |=(1ull << i);

    }

    int filasEliminadas=0;

    unsigned long long* ptrEscritura=tablero+(alto-1);

    unsigned long long* ptrLectura=tablero+(alto-1);

    //recorrer utilizando aritmetica de punteros
    while(ptrLectura>=tablero){
        if((*ptrLectura & mascara)==mascara){
            filasEliminadas++;

        }else{
            if(ptrEscritura!=ptrLectura){
                *ptrEscritura=*ptrLectura;
            }
            ptrEscritura--;
        }
        ptrLectura--;
    }

    unsigned long long* ptr=tablero;
    while(ptr<=ptrEscritura){
        *ptr=0ull;
        ptr++;
    }

    return filasEliminadas;
}

void ImprimirTablero(unsigned long long*tablero, int alto,int ancho){

    cout<< "Tablero " << alto << "x" << ancho << ":" << endl;
    cout<< endl;

    for(int fila=0; fila<alto;fila++){
        for(int col=0; col<ancho; col++){
            if(tablero[fila] & (1ull<<col)){
                cout<< "#";

            }else{
                cout<<".";
            }

        }
        cout<< endl;
    }
    cout<< endl;

}











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


void quitarPieza (unsigned long long* tablero, unsigned short pieza, int x, int y){

    for (int fila = 0; fila<4 ; fila++){
        for(int col=0; col<4 ; col++){
            int bit = 15 - ((fila*4)+ col);

            if((pieza >> bit) & 1){

                int colF = x+col;
                int filaF = y+fila;

                unsigned long long maskPosicion = 1ull << colF;

                unsigned long long maskBorrado = ~maskPosicion;

                tablero[filaF]&= maskBorrado;
            }
        }
    }

}


bool movimientoValido(unsigned long long* tablero,
                      unsigned short pieza, int x, int y,
                      int ancho, int alto){

    for (int fila = 0; fila<4 ; fila++){
        for(int col=0; col<4 ; col++){
            int bit = 15 - ((fila*4)+ col);


            bool hayBloque = (pieza>>bit)& 1;

            if(hayBloque){

                int nuevoX = x+col;
                int nuevoY = y+fila;

                if (nuevoX<0 || nuevoX >= ancho || nuevoY >= alto){return false;}


                if (nuevoY >=0){

                    unsigned long long mask = 1ull<<nuevoX;

                    bool ocupado = tablero [nuevoY] & mask;
                    if(ocupado){return false;}

                }
            }

        }
    }

    return true;
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

void ColocarPieza(unsigned long long* tablero, unsigned short piezaActual, int x, int y){

    for(int fila = 0; fila < 4; fila++){
        for(int col = 0; col < 4; col++){
            int bit = 15 - ((fila * 4) + col);
            if((piezaActual >> bit) & 1){
                int colF  = x + col;
                int filaF = y + fila;
                unsigned long long maskPosicion = 1ull << colF;
                // OR: enciende el bit en el tablero
                tablero[filaF] |= maskPosicion;
            }
        }
    }

}













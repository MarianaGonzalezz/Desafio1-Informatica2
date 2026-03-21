#include <iostream>
#include "piezas.h"

using namespace std;

//Rotar pieza I

unsigned short rotarI(int rotacion){

    unsigned short rI = 0;

    if (rotacion == 0){ //base

        rI |= (1<<11);
        rI |= (1<<10);
        rI |= (1<<9);
        rI |= (1<<8);
    }
    else{

        rI |= (1<<13);
        rI |= (1<<9);
        rI |= (1<<5);
        rI |= (1<<1);
    }

    return rI;
}


////Rotar pieza T
unsigned short rotarT(int rotacion){

    unsigned short rT = 0;

    if (rotacion == 0){ //base


        rT |= (1<<14);
        rT |= (1<<11);
        rT |= (1<<10);
        rT |= (1<<9);
    }
    else if (rotacion == 1){

        rT |= (1<<14);
        rT |= (1<<10);
        rT |= (1<<9);
        rT |= (1<<6);
    }
    else if (rotacion == 2){

        rT |= (1<<11);
        rT |= (1<<10);
        rT |= (1<<9);
        rT |= (1<<6);
    }
    else {

        rT |= (1<<14);
        rT |= (1<<11);
        rT |= (1<<10);
        rT |= (1<<6);
    }

    return rT;

}

////Rotar pieza S
unsigned short rotarS( int rotacion){

    unsigned short rS = 0;

    if (rotacion == 0){ // base
        rS |= (1<<14);
        rS |= (1<<13);
        rS |= (1<<11);
        rS |= (1<<10);
    }
    else {
        rS |= (1<<14);
        rS |= (1<<10);
        rS |= (1<<9);
        rS |= (1<<5);
    }

    return rS;
}

////Rotar pieza Z

unsigned short rotarZ( int rotacion){

    unsigned short rZ = 0;

    if (rotacion == 0){ //base

        rZ |= (1<<15);
        rZ |= (1<<14);
        rZ |= (1<<10);
        rZ |= (1<<9);

    }
    else {
        rZ |= (1<<14);
        rZ |= (1<<11);
        rZ |= (1<<10);
        rZ |= (1<<7);
    }

    return rZ;

}

////Rotar pieza J
unsigned short rotarJ(int rotacion){

    unsigned short rJ = 0;

    if (rotacion == 0){ //base
       rJ |= (1<<14);
       rJ |= (1<<10);
       rJ |= (1<<7);
       rJ |= (1<<6);
    }
    else if (rotacion == 1){
        rJ |= (1<<15);
        rJ |= (1<<11);
        rJ |= (1<<10);
        rJ |= (1<<9);
    }
    else if (rotacion == 2){
        rJ |= (1<<14);
        rJ |= (1<<13);
        rJ |= (1<<10);
        rJ |= (1<<6);
    }
    else {
        rJ |= (1<<11);
        rJ |= (1<<10);
        rJ |= (1<<9);
        rJ |= (1<<5);
    }
    return rJ;
}

////Rotar pieza L

unsigned short rotarL(int rotacion){

    unsigned short rL = 0;

    if (rotacion == 0){// base
        rL |= (1<<15);
        rL |= (1<<11);
        rL |= (1<<7);
        rL |= (1<<6);
    }
    else if (rotacion == 1){
        rL |= (1<<11);
        rL |= (1<<10);
        rL |= (1<<9);
        rL |= (1<<7);
    }
    else if (rotacion == 2){
         rL |= (1<<15);
         rL |= (1<<14);
         rL |= (1<<10);
         rL |= (1<<6);
    }
    else {

         rL |= (1<<13);
         rL |= (1<<11);
         rL |= (1<<10);
         rL |= (1<<9);
    }
    return rL;
}



//Funcion para imprimir cada pieza en su representacion en binario y como una matriz 4*4

void piezasEnMatriz(unsigned short piezas){
    for(int fila = 0; fila<4 ; fila++){
        for (int col=0; col<4; col++){
            int bit = 15 - ((fila*4) + col);
            if ((piezas >> bit) & 1)
                cout<<"#";
            else
                cout<<".";
        }
        cout<<endl;
    }
    cout<<endl;
}

unsigned short rotarConIndice(int indice, int rotacion)
{

    switch(indice){
        case 0: return rotarI(rotacion);
        case 1: return 0b0110011000000000; //Cuadrado no rota
        case 2: return rotarT(rotacion);
        case 3: return rotarS(rotacion);
        case 4: return rotarZ(rotacion);
        case 5: return rotarJ(rotacion);
        case 6: return rotarL(rotacion);
        default: return 0b0110011000000000; // pieza O
    }

}










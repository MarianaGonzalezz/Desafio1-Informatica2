#include <iostream>
#include "piezas.h"

using namespace std;

////Rotar pieza I
unsigned short rotarI(unsigned short pieza, int rotacion){

    unsigned short rI = 0;

    if (rotacion == 0){
        unsigned short I1 = 1<<11;
        unsigned short I2 = 1<<10;
        unsigned short I3 = 1<<9;
        unsigned short I4 = 1<<8;

        if (pieza & I1) rI |= (1<<13);
        if (pieza & I2) rI |= (1<<9);
        if (pieza & I3) rI |= (1<<5);
        if (pieza & I4) rI |= (1<<1);

    }
    else{

        unsigned short I1 = 1<<13;
        unsigned short I2 = 1<<9;
        unsigned short I3 = 1<<5;
        unsigned short I4 = 1<<1;

        if (pieza & I1) rI |= (1<<11);
        if (pieza & I2) rI |= (1<<10);
        if (pieza & I3) rI |= (1<<9);
        if (pieza & I4) rI |= (1<<8);
    }

    return rI;
}


////Rotar pieza T
unsigned short rotarT(unsigned short pieza, int rotacion){

    unsigned short rT = 0;

    if (rotacion == 0){

        unsigned short T1 = 1<<14;
        unsigned short T2 = 1<<11;
        unsigned short T3 = 1<<10;
        unsigned short T4 = 1<<9;

        if (pieza & T1) rT |= (1<<14);
        if (pieza & T2) rT |= (1<<10);
        if (pieza & T3) rT |= (1<<9);
        if (pieza & T4) rT |= (1<<6);
    }
    else if (rotacion == 1){
        unsigned short T1 = 1<<14;
        unsigned short T2 = 1<<10;
        unsigned short T3 = 1<<9;
        unsigned short T4 = 1<<6;
        if (pieza & T1) rT |= (1<<11);
        if (pieza & T2) rT |= (1<<10);
        if (pieza & T3) rT |= (1<<9);
        if (pieza & T4) rT |= (1<<6);
    }
    else if (rotacion == 2){
        unsigned short T1 = 1<<11;
        unsigned short T2 = 1<<10;
        unsigned short T3 = 1<<9;
        unsigned short T4 = 1<<6;
        if (pieza & T1) rT |= (1<<14);
        if (pieza & T2) rT |= (1<<11);
        if (pieza & T3) rT |= (1<<10);
        if (pieza & T4) rT |= (1<<6);
    }
    else {
        unsigned short T1 = 1<<14;
        unsigned short T2 = 1<<11;
        unsigned short T3 = 1<<10;
        unsigned short T4 = 1<<6;
        if (pieza & T1) rT |= (1<<14);
        if (pieza & T2) rT |= (1<<11);
        if (pieza & T3) rT |= (1<<10);
        if (pieza & T4) rT |= (1<<9);
    }

    return rT;

}

////Rotar pieza S
unsigned short rotarS(unsigned short pieza, int rotacion){

    unsigned short rS = 0;

    if (rotacion == 0){

        unsigned short S1 = 1<<14;
        unsigned short S2 = 1<<13;
        unsigned short S3 = 1<<11;
        unsigned short S4 = 1<<10;

        if (pieza & S1) rS |= (1<<14);
        if (pieza & S2) rS |= (1<<10);
        if (pieza & S3) rS |= (1<<9);
        if (pieza & S4) rS |= (1<<5);
    }
    else {

        unsigned short S1 = 1<<14;
        unsigned short S2 = 1<<10;
        unsigned short S3 = 1<<9;
        unsigned short S4 = 1<<5;

        if (pieza & S1) rS |= (1<<14);
        if (pieza & S2) rS |= (1<<13);
        if (pieza & S3) rS |= (1<<11);
        if (pieza & S4) rS |= (1<<10);
    }

    return rS;
}

////Rotar pieza Z

unsigned short rotarZ(unsigned short pieza, int rotacion){

    unsigned short rZ = 0;

    if (rotacion == 0){

        unsigned short Z1 = 1<<15;
        unsigned short Z2 = 1<<14;
        unsigned short Z3 = 1<<10;
        unsigned short Z4 = 1<<9;

        if (pieza & Z1) rZ |= (1<<14);
        if (pieza & Z2) rZ |= (1<<11);
        if (pieza & Z3) rZ |= (1<<10);
        if (pieza & Z4) rZ |= (1<<7);
    }
    else {

        unsigned short Z1 = 1<<14;
        unsigned short Z2 = 1<<11;
        unsigned short Z3 = 1<<10;
        unsigned short Z4 = 1<<7;

        if (pieza & Z1) rZ |= (1<<15);
        if (pieza & Z2) rZ |= (1<<14);
        if (pieza & Z3) rZ |= (1<<10);
        if (pieza & Z4) rZ |= (1<<9);

    }

    return rZ;

}

////Rotar pieza J
unsigned short rotarJ(unsigned short pieza, int rotacion){

    unsigned short rJ = 0;

    if (rotacion == 0){

        unsigned short J1 = 1<<14;
        unsigned short J2 = 1<<10;
        unsigned short J3 = 1<<7;
        unsigned short J4 = 1<<6;

        if (pieza & J1) rJ |= (1<<15);
        if (pieza & J2) rJ |= (1<<11);
        if (pieza & J3) rJ |= (1<<10);
        if (pieza & J4) rJ |= (1<<9);
    }
    else if (rotacion == 1){

        unsigned short J1 = 1<<15;
        unsigned short J2 = 1<<11;
        unsigned short J3 = 1<<10;
        unsigned short J4 = 1<<9;

        if (pieza & J1) rJ |= (1<<14);
        if (pieza & J2) rJ |= (1<<13);
        if (pieza & J3) rJ |= (1<<10);
        if (pieza & J4) rJ |= (1<<6);
    }
    else if (rotacion == 2){

        unsigned short J1 = 1<<14;
        unsigned short J2 = 1<<13;
        unsigned short J3 = 1<<10;
        unsigned short J4 = 1<<6;

        if (pieza & J1) rJ |= (1<<11);
        if (pieza & J2) rJ |= (1<<10);
        if (pieza & J3) rJ |= (1<<9);
        if (pieza & J4) rJ |= (1<<5);
    }
    else {
        unsigned short J1 = 1<<11;
        unsigned short J2 = 1<<10;
        unsigned short J3 = 1<<9;
        unsigned short J4 = 1<<5;

        if (pieza & J1) rJ |= (1<<14);
        if (pieza & J2) rJ |= (1<<10);
        if (pieza & J3) rJ |= (1<<7);
        if (pieza & J4) rJ |= (1<<6);
    }
    return rJ;
}

////Rotar pieza L

unsigned short rotarL(unsigned short pieza, int rotacion){

    unsigned short rL = 0;

    if (rotacion == 0){

        unsigned short L1 = 1<<15;
        unsigned short L2 = 1<<11;
        unsigned short L3 = 1<<7;
        unsigned short L4 = 1<<6;

        if (pieza & L1) rL |= (1<<13);
        if (pieza & L2) rL |= (1<<11);
        if (pieza & L3) rL |= (1<<10);
        if (pieza & L4) rL |= (1<<9);
    }
    else if (rotacion == 1){

        unsigned short L1 = 1<<13;
        unsigned short L2 = 1<<11;
        unsigned short L3 = 1<<10;
        unsigned short L4 = 1<<9;

        if (pieza & L1) rL |= (1<<15);
        if (pieza & L2) rL |= (1<<14);
        if (pieza & L3) rL |= (1<<10);
        if (pieza & L4) rL |= (1<<6);
    }
    else if (rotacion == 2){

        unsigned short L1 = 1<<15;
        unsigned short L2 = 1<<14;
        unsigned short L3 = 1<<10;
        unsigned short L4 = 1<<6;

        if (pieza & L1) rL |= (1<<11);
        if (pieza & L2) rL |= (1<<10);
        if (pieza & L3) rL |= (1<<9);
        if (pieza & L4) rL |= (1<<7);
    }
    else {
        unsigned short L1 = 1<<11;
        unsigned short L2 = 1<<10;
        unsigned short L3 = 1<<9;
        unsigned short L4 = 1<<7;

        if (pieza & L1) rL |= (1<<15);
        if (pieza & L2) rL |= (1<<11);
        if (pieza & L3) rL |= (1<<7);
        if (pieza & L4) rL |= (1<<6);
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

unsigned short rotarConIndice(unsigned short pieza, int indice, int rotacion){

    switch(indice){
        case 0: return rotarI(pieza,rotacion);
        case 1: return pieza; //Cuadrado no rota
        case 2: return rotarT(pieza,rotacion);
        case 3: return rotarS(pieza,rotacion);
        case 4: return rotarZ(pieza,rotacion);
        case 5: return rotarJ(pieza,rotacion);
        case 6: return rotarL(pieza,rotacion);
        default: return pieza;
    }

}










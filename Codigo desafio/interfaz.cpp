#include <iostream>
#include "interfaz.h"
#include "tablero.h"
#include "piezas.h"
#include "cstdlib"
#include "ctime"
#include "tablero.h"

using namespace std;

int pedirAncho(){

    int ancho;

    do{
        cout<<"Ingrese el ancho del tablero: ";
        cin>>ancho;
        if(ancho<8 || ancho % 8 !=0){
            cout<<"ERROR: El ancho debe ser multiplo, mayor o igual a 8."<<'\n';
        }
    } while (ancho<8 || ancho % 8 !=0);
    return ancho;
}

int pedirAlto(){

    int alto;
    do{
        cout<<"Ingrese el alto del tablero: ";
        cin>>alto;

        if(alto<8){
            cout<<"ERROR: El alto debe ser mayor que 8: ";
        }
    } while (alto<8);
    return alto;
}

char leerComando(){
    char tecla;
    do{
        cout<<"[A] Mover pieza hacia la izquierda\n";
        cout<<"[D] Mover pieza hacia la derecha\n";
        cout<<"[S] Mover pieza hacia abajo\n";
        cout<<"[W] Rotar la pieza\n";
        cout<<"[Q] Salir\n";

        cout<<"Ingrese una opcion: ";
        cin>>tecla;
    } while(tecla != 'a' && tecla != 'A' &&
             tecla != 'd' && tecla != 'D' &&
             tecla != 's' && tecla != 'S' &&
             tecla != 'w' && tecla != 'W' &&
             tecla != 'q' && tecla != 'Q'
             );
    return tecla;
}

void inicializarJuego(unsigned short piezas[],
                      int& indice, unsigned short& piezaActual,int& rotacion,
                      int& x, int& y){

    srand(time(0));


    piezas [0] = 0b0000111100000000; //I
    piezas [1] = 0b0110011000000000; //O
    piezas [2] = 0b0100111000000000; //T
    piezas [3] = 0b0110110000000000; //S
    piezas [4] = 0b1100011000000000; //Z
    piezas [5] = 0b0100010011000000; //J
    piezas [6] = 0b1000100011000000; //L

    indice = rand()%7;

    piezaActual = piezas[indice];
    rotacion = 0;
    x = 0;
    y = 0;
}

void procesoComandos(char comando, unsigned long long* tablero,
                     unsigned short& piezaActual, int& x, int& y,
                     int& rotacion, int& indice, int ancho, int alto, unsigned short piezas[], bool& gameOver){

    quitarPieza(tablero, piezaActual, x, y);

    if(comando == 'a' || comando == 'A'){
        if(movimientoValido(tablero, piezaActual, x-1, y, ancho, alto)){
            x--;
        }
    }

    else if(comando == 'd' || comando == 'D'){
        if(movimientoValido(tablero, piezaActual, x+1, y, ancho, alto)){
            x++;
        }
    }

    else if(comando == 's' || comando == 'S'){
        if(movimientoValido(tablero, piezaActual, x, y+1, ancho, alto)){
            y++;
        } else {
            ColocarPieza (tablero, piezaActual, x,y);
            LimpiarFilas(tablero, alto, ancho);
            if(!generarNuevaPieza(piezas, indice, piezaActual, rotacion, x,y,ancho, tablero, alto)){
                cout<<"\nGAME OVER\n";
                gameOver = true;
            }
        }
    }

    else if(comando == 'w' || comando == 'W'){

        //cout << "indice: "<< indice<<endl;
        //piezasEnMatriz(piezaActual);

        int rotacionActual;

        if (indice == 0 || indice == 3 || indice == 4){ //Piezas con 2 rotaciones
            rotacionActual = (rotacion + 1) % 2;
        }
        else if (indice == 1){ //Pieza con 1 rotacion O
            rotacionActual = 0;
        }
        else { // Piezas con 4 rotaciones
            rotacionActual = (rotacion +1) % 4;
        }

        unsigned short nueva = rotarConIndice(indice, rotacionActual);

        if(movimientoValido(tablero, nueva, x, y, ancho, alto)){
            piezaActual = nueva;
            rotacion = rotacionActual;
        }
    }

    ColocarPieza(tablero, piezaActual, x, y);


}

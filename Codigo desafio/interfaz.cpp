#include "iostream"
#include "interfaz.h"
#include "piezas.h"
#include "cstdlib"
#include "ctime"

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


int main(){

    srand(time(0));
    unsigned short piezas[7] = {
        0b0000111100000000, // I
        0b0110011000000000, // O
        0b0100111000000000, // T
        0b0110110000000000, // S
        0b1100011000000000, // Z
        0b0100010011000000, // J
        0b1000100011000000 // L
    };

    int indice = rand()%7;
    unsigned short piezaActual = piezas[indice];
    int rotacion = 0;

    //int ancho = pedirAncho();
    //int alto = pedirAlto();



    //unsigned short rotada = rotarT(piezas[2],0);

    //piezasEnMatriz(rotada);

    char comando;
    do{
        comando = leerComando();

        if(comando == 'a' || comando == 'A'){

        }

        if(comando == 'd' || comando == 'D'){
            //
        }

        if(comando == 's' || comando == 'S'){
            //
        }

        if(comando == 'w' || comando == 'W'){
            rotacion = (rotacion +1) % 4;
            piezaActual = rotarConIndice(piezaActual, indice, rotacion);

            piezasEnMatriz(piezaActual);
        }

        if(comando == 'q' || comando == 'Q'){
            //
        }
    } while (comando!='q' && comando!='Q');
    cout<<"Juego terminado :) ";

    return 0;
}

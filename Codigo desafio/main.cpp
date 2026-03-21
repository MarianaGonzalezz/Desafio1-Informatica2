#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "interfaz.h"



using namespace std;

int main(){
    int ancho=pedirAncho();
    int alto=pedirAlto();

    unsigned long long* tablero= CrearTablero(alto);

    unsigned short piezas [7];
    unsigned short piezaActual;
    int indice, rotacion, x, y;

    inicializarJuego(piezas, indice, piezaActual, rotacion, x, y);

    ColocarPieza(tablero, piezaActual, x, y);

    ImprimirTablero(tablero, alto, ancho);

    char comando;
    bool gameOver = false;

    do{
        comando = leerComando();
        procesoComandos(comando, tablero, piezaActual, x, y, rotacion, indice, ancho, alto, piezas, gameOver);
        LimpiarFilas(tablero, alto, ancho);
        ImprimirTablero(tablero, alto, ancho);


    } while (!gameOver && comando!='q' && comando!='Q');
    DestruirTablero(tablero);
    cout<<"Juego terminado :) ";

    return 0;

}

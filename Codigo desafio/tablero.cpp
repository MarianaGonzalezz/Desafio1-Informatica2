#include <iostream>


unsigned long long* CrearTablero(int ancho, int alto){

    unsigned long long* tablero= new unsigned long long[alto];

    for(int i=0;i<alto;i++){
        tablero[i]=0ull;
    }
    return tablero;
}

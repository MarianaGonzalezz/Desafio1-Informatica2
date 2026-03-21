#ifndef TABLERO_H
#define TABLERO_H

unsigned long long* CrearTablero(int alto);
void DestruirTablero(unsigned long long* tablero);
int LimpiarFilas(unsigned long long* tablero, int alto, int ancho);
void quitarPieza(unsigned long long* tablero, unsigned short pieza, int x, int y);
bool movimientoValido(unsigned long long* tablero, unsigned short pieza,int x, int y, int ancho, int alto);
void generarNuevaPieza(unsigned short piezas[],int& indice, unsigned short& piezaActual, int& rotacion,
                       int& x, int& y, int ancho);
void ImprimirTablero(unsigned long long*tablero, int alto,int ancho);
void ColocarPieza(unsigned long long* tablero, unsigned short piezaActual, int x, int y);


#endif // TABLERO_H

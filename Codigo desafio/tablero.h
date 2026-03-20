#ifndef TABLERO_H
#define TABLERO_H

unsigned long long* CrearTablero(int alto);
void DestruirTablero(unsigned long long* tablero);
int LimpiarFilas(unsigned long long* tablero, int alto, int ancho);
void quitarPieza(unsigned long long* tablero, unsigned short pieza, int x, int y);
bool movimientoValido(unsigned long long* tablero, unsigned short pieza,int x, int y, int ancho, int alto);
void ImprimirTablero(unsigned long long*tablero, int alto,int ancho);


#endif // TABLERO_H

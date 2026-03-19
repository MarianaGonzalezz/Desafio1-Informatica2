#ifndef TABLERO_H
#define TABLERO_H

unsigned long long* CrearTablero(int alto);
void DestruirTablero(unsigned long long* tablero);
int LimpiarFilas(unsigned long long* tablero, int alto, int ancho);
void ImprimirTablero(unsigned long long*tablero, int alto,int ancho);
#endif // TABLERO_H

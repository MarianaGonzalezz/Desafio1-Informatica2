#ifndef INTERFAZ_H
#define INTERFAZ_H

int pedirAncho();
int pedirAlto();
char leerComando();

void inicializarJuego(unsigned short piezas[],
                      int& indice, unsigned short& piezaActual,
                      int& rotacion, int& x, int& y);

void procesoComandos(char comando, unsigned long long* tablero,
                     unsigned short& piezaActual, int& x, int& y,
                     int& rotacion, int indice, int ancho, int alto, unsigned short piezas[]);

#endif

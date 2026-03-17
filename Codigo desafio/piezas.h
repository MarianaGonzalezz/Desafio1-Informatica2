#ifndef PIEZAS_H
#define PIEZAS_H

unsigned short rotarI(unsigned short pieza, int rotacion);
unsigned short rotarT(unsigned short pieza, int rotacion);
unsigned short rotarS(unsigned short pieza, int rotacion);
unsigned short rotarZ(unsigned short pieza, int rotacion);
unsigned short rotarJ(unsigned short pieza, int rotacion);
unsigned short rotarL(unsigned short pieza, int rotacion);

unsigned short rotarConIndice(unsigned short pieza, int tipo, int rotacion);

void piezasEnMatriz(unsigned short piezas);

#endif // PIEZAS_H

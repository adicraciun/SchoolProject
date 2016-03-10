/*
 * Cheltuiala.h
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#ifndef CHELTUIALA_H_
#define CHELTUIALA_H_

typedef struct {
    int nrAp, suma, tip;
} Cheltuiala;

Cheltuiala* Cheltuiala_create (int nrAp, int suma, char* tip);

int Cheltuiala_getNrAp(Cheltuiala *a);

int Cheltuiala_getSuma(Cheltuiala *a);

void Cheltuiala_destroy(Cheltuiala *a);

char* Cheltuiala_getTip(Cheltuiala *a);

void Cheltuiala_test();

#endif /* CHELTUIALA_H_ */

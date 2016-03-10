/*
 * Controller.h
 *
 *  Created on: 10 mar. 2016
 *      Author: Korakiun
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Cheltuiala_validator.h"

List* Controller_getListaOrd_tip(List*);

List* Controller_getListaOrd_suma(List*);

List* Controller_getListaFiltrat_suma(List*, int);

List* Controller_getListaFiltrat_tip(List* lista, char *tip);

List* Controller_getListaFiltrat_nrAp(List* lista, int);

void Controller_adauga_cheltuiala(List* lista, int nrAp, int suma, char* tip);

void Controller_sterge_cheltuiala(List* lista, int nr);

void Controller_actualizeaza_cheltuiala(List* lista, int nr, int sum, char* tip);


#endif /* CONTROLLER_H_ */

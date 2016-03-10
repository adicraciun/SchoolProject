/*
 * Controller.c
 *
 *  Created on: 10 mar. 2016
 *      Author: Korakiun
 */

#include <string.h>
#include <stdlib.h>
#include "Cheltuiala.h"
#include "List.h"
#include "Controller.h"


int Controller_cmp_tip(const void *p1, const void *p2) {
	return strcmp(Cheltuiala_getTip((*(Cheltuiala**)p1)), Cheltuiala_getTip((*(Cheltuiala**)p2)));
}

List* Controller_getCopy(List* lista) {
	List *listaOrd;

	listaOrd = List_create();

	List_copy(listaOrd, lista);

	return listaOrd;
}

List* Controller_getListaOrd_tip(List* lista) {
	List *listaOrd = Controller_getCopy(lista);

	qsort(listaOrd->data, listaOrd->len, sizeof(Cheltuiala*), Controller_cmp_tip);

	return listaOrd;
}


int Controller_cmp_suma(const void *p1, const void *p2) {
	if ((*(Cheltuiala**)p1)->suma < (*(Cheltuiala**)p2)->suma)
		return -1;
	if ((*(Cheltuiala**)p1)->suma == (*(Cheltuiala**)p2)->suma)
		return 0;
	return 1;
}

List* Controller_getListaOrd_suma(List* lista) {
	List *listaOrd = Controller_getCopy(lista);

	qsort(listaOrd->data, listaOrd->len, sizeof(Cheltuiala*), Controller_cmp_suma);

	return listaOrd;
}


List* Controller_getListaFiltrat_suma(List* lista, int suma) {
	List* rez = List_create();

	int i;

	for (i = 0; i < lista->len; ++i) {
		Cheltuiala *c = List_getElem(lista, i);

		if (Cheltuiala_getSuma(c) == suma)
			List_insert(rez, c);
	}

	return rez;
}

List* Controller_getListaFiltrat_tip(List* lista, char *tip) {
	List* rez = List_create();

	int i;

	for (i = 0; i < lista->len; ++i) {
			Cheltuiala *c = List_getElem(lista, i);

			if (strcmp(Cheltuiala_getTip(c), tip) == 0)
				List_insert(rez, c);
	}

	return rez;
}

List* Controller_getListaFiltrat_nrAp(List* lista, int nrAp) {
	List* rez = List_create();

	int i;

	for (i = 0; i < lista->len; ++i) {
		Cheltuiala *c = List_getElem(lista, i);

		if (Cheltuiala_getNrAp(c) == nrAp)
			List_insert(rez, c);
	}

	return rez;
}

void Controller_adauga_cheltuiala(List* lista, int nrAp, int suma, char* tip) {
	Cheltuiala *c = Cheltuiala_create(nrAp, suma, tip);
	List_insert(lista, c);
}

void Controller_sterge_cheltuiala(List* lista, int nr) {
	List_deleteElem(lista, nr);
}

void Controller_actualizeaza_cheltuiala(List* lista, int nr, int sum, char* tip) {
	Cheltuiala *cur = List_getElem(lista, nr);

	Cheltuiala *newOne = Cheltuiala_create(Cheltuiala_getNrAp(cur), sum, tip);
	lista->data[nr] = newOne;
}




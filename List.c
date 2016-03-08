/*
 * List.c
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
#include "Cheltuiala.h"

List* List_create() {
    List* obj = malloc(sizeof(List));
    obj->len = 0;
    obj->capacity = 2;
    obj->data = malloc(sizeof(Cheltuiala*) * obj->capacity);
    return obj;
}

void List_Realocate(List *a) {
    Cheltuiala** newData = malloc(sizeof(Cheltuiala*) * a->capacity * 2);
    int i;

    for (i = 0; i < a->len; ++i)
        newData[i] = a->data[i];

    a->capacity *= 2;
    a->data = newData;
}


void List_insert(List* a, Cheltuiala* elem) {
    if (a->len == a->capacity) {
        List_Realocate(a);
    }

    a->data[a->len] = elem;
    (a->len)++;
}

void List_destroy(List *a) {
    int i;

    for (i = 0; i < a->len; ++i)
        Cheltuiala_destroy(a->data[i]);

    free(a->data);
    free(a);
}

void List_deleteElem(List *a, int poz) {
	Cheltuiala *t = a->data[poz];
	int i;
	for (i = poz; i < (a->len) - 1; ++i)
		a->data[poz] = a->data[poz + 1];
	free(t);
	(a->len)--;
}


Cheltuiala* List_getElem(List *a, int poz) {
    return a->data[poz];
}

void List_test() {
	List *a = List_create();

	Cheltuiala *c0 = Cheltuiala_create(14, 120, "canal");
	Cheltuiala *c1 = Cheltuiala_create(15, 123, "apa");
	Cheltuiala *c2 = Cheltuiala_create(16, 124, "canal");

	List_insert(a, c0);
	List_insert(a, c1);

	assert(List_getElem(a, 0) == c0);
	assert(List_getElem(a, 1) == c1);

	List_insert(a, c2);

	assert(List_getElem(a, 1) == c1);
	assert(List_getElem(a, 2) == c2);
}




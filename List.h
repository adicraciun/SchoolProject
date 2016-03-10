/*
 * List.h
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#ifndef LIST_H_
#define LIST_H_

#include "Cheltuiala.h"

typedef struct {
    int len, capacity;
    Cheltuiala** data;
} List;

List* List_create();

void List_insert(List* a, Cheltuiala* elem);

void List_modify(List *a, Cheltuiala *c, int poz);

void List_destroy(List *a);

Cheltuiala* List_getElem(List *a, int poz);

void List_copy(List *b, List *a);

void List_test();

void List_deleteElem(List *a, int poz);


#endif /* LIST_H_ */

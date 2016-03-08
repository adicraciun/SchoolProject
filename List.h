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

void List_destroy(List *a);

Cheltuiala* List_getElem(List *a, int poz);

void List_test();



#endif /* LIST_H_ */

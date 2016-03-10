/*
 * List.h
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#ifndef LIST_H_
#define LIST_H_

#include "Cheltuiala.h"

typedef Cheltuiala* TElem;

typedef struct {
    int len, capacity;
    TElem* data;
} List;

List* List_create();

void List_insert(List* a, TElem elem);

void List_modify(List *a, TElem c, int poz);

void List_destroy(List *a);

TElem List_getElem(List *a, int poz);

void List_copy(List *b, List *a);

void List_test();

void List_deleteElem(List *a, int poz);


#endif /* LIST_H_ */

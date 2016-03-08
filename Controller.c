/*
 * Controller.c
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#include "Controller.h"
#include "Cheltuiala.h"
#include "List.h"

void Controller_add_apartament (List *a, int nrAp, int suma, char* tip) {
	Cheltuiala *c = Cheltuiala_create(nrAp, suma, tip);
	List_insert(a, c);
}

/*
 * Cheltuiala_validator.c
 *
 *  Created on: 10 mar. 2016
 *      Author: Korakiun
 */

#include "Cheltuiala_validator.h"
#include "Cheltuiala.h"
#include <errno.h>
#include <string.h>
#include "errors.h"

int Cheltuiala_validator(int nrAp, int suma, char* tip) {
	char* v[4];
	v[0] = "apa";
	v[1] = "canal";
	v[2] = "incalzire";
	v[3] = "gaz";

	int i;

	if (suma <= 0) {
		errno = SUMAERROR;
		return 0;
	}

	if (nrAp <= 0) {
		errno = NRAPERROR;
		return 0;
	}

	for (i = 0; i < 4; ++i) {
		if (strcmp(v[i], tip) == 0) {
			errno = 0;
			return 1;
		}
	}

	errno = TIPERROR;

	return 0;
}

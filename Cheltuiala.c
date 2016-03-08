/*
 * Cheltuiala.c
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */


#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Cheltuiala.h"

/*
    Prototipul structurii
*/

/*
    Functie interna.
    Returneza un array de stringuri cu cheltuielile posibile
*/

char** _getArrayOfTip() {
    char* v[4];
    v[0] = "apa";
    v[1] = "canal";
    v[2] = "incalzire";
    v[3] = "gaz";

    return v;
}
/*
    Functie interna, utila pentru a returna tipul unei cheltuili codat ca si numar
    Parametrii: un string cu tipul
    Returneaza un int cu tipul


*/

int _getTip(char* tip) {
    int i;

    char** v = _getArrayOfTip();

    for (i = 0; i < 4; ++i) {
        if (strcmp(tip, v[i]) == 0)
            return i;
    }
    return -1;
}

/*
    Functie ce creeaza o cheltuiala.
    Parametrii: informatiile despre cheltuiala
    Returneaza un pointer la o cheltuiala

*/

Cheltuiala* Cheltuiala_create (int nrAp, int suma, char* tip) {
    int tipInt = _getTip(tip);

    Cheltuiala* a;
    a = (Cheltuiala* )malloc(sizeof(Cheltuiala));
    (*a).nrAp = nrAp;
    (*a).suma = suma;
    (*a).tip = tipInt;

    return a;
}

/*
    Functie ce acceseaza numarul de apartament unei cheltuieli.
    Parametrii: un pointer la o cheltuiala
    Returneaza numarul de apartament
*/

int Cheltuiala_getNrAp(Cheltuiala *a) {
    return (*a).nrAp;
}

/*
    Functie ce acceseaza suma unei cheltuieli.
    Parametrii: un pointer la o cheltuiala
    Returneaza suma
*/

int Cheltuiala_getSuma(Cheltuiala *a) {
    return (*a).suma;
}


/*
    Functie ce acceseaza tipul unei cheltuieli.
    Parametrii: un pointer la o cheltuiala
    Returneaza tipul
*/

char* Cheltuiala_getTip(Cheltuiala *a) {
    char** v = _getArrayOfTip();
    return v[(*a).tip];
}

/*
    Functia ce testeaza creearea unei cheltuieli
*/

void Cheltuiala_test() {
    Cheltuiala *a;

    a = Cheltuiala_create(14, 120, "canal");
    assert(Cheltuiala_getNrAp(a) == 14);
    assert(Cheltuiala_getSuma(a) == 120);
    assert(Cheltuiala_getTip(a) == "canal");

}

void Cheltuiala_destroy(Cheltuiala *a) {
    free(a);
}

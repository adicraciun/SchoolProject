/*
 * UI.c
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "UI.h"
#include "List.h"
#include "Cheltuiala.h"

void UI_start(List* lista) {
    printf("Bine ai venit in gestionarul de cheltuieli!\n");
    while (1) {
        int op;
        printf("\nMeniu: \n");
        printf("1) Adauga cheltuiala noua\n");
        printf("2) Actualizeaza cheltuiala\n");
        printf("3) Stergere cheltuiala\n");
        printf("4) Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul,apartament)\n");
        printf("5) Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)\n");
        printf("6) Iesi\n");
        printf("\nOptiunea ta: ");
        scanf("%d", &op);

        switch(op) {

        case 1: UI_adauga_cheltuiala(lista); break;
        case 2: UI_actualizeaza_cheltuiala(lista); break;
        case 3: UI_sterge_cheltuiala(lista); break;
        case 4: UI_vizualizare_lista_filtrat(lista); break;
//        case 5: UI_vizualizare_lista_ordonat(lista); break;

        }
        if (op == 6) break;
        getch();
    }
}

void UI_adauga_cheltuiala(List* lista) {
	int nrAp, suma;
	char tip[50];

	printf("\nNumarul apartamentului: ");
	scanf("%d", &nrAp);
	printf("Suma: ");
	scanf("%d", &suma);
	printf("Tipul: ");
	scanf("%s", tip);

	Cheltuiala *c = Cheltuiala_create(nrAp, suma, tip);
	List_insert(lista, c);

	printf("\nADAUGAT CU SUCCES!\n");
}

int UI_getNr_cheltuiala(List* lista) {
	int i, nr, nrCheltuieli = lista->len;
	if (nrCheltuieli == 0) {
		printf("Nici o cheltuiala in baza de date!\n");
		return -1;
	}

	printf("\nCheltuieli aflate in baza de date:\n");
	for (i = 0; i < nrCheltuieli; ++i) {
		Cheltuiala *c = List_getElem(lista, i);
		UI_afiseaza_cheltuiala(c, i);
	}

	printf("\nSelecteaza cheltuiala: ");
	scanf("%d", &nr);

	if (nr < 0 || nr >= nrCheltuieli) {
		printf("Numarul cheltuielii invalid\n");
		return -1;
	}

	return nr;
}

void UI_actualizeaza_cheltuiala(List* lista) {
	int nr;
	printf("\n ACTUALIZARE CHELTUIALA\n");
	nr = UI_getNr_cheltuiala(lista);

	if (nr == -1) {
		return;
	}
	Cheltuiala *cur = List_getElem(lista, nr);

	int sum;
	char* tip;
	tip = malloc(sizeof(char) * 50);
	printf("\nNoua suma: ");
	scanf("%d", &sum);
	printf("Noul tip: ");
	scanf("%s", tip);

	Cheltuiala *newOne = Cheltuiala_create(Cheltuiala_getNrAp(cur), sum, tip);
	lista->data[nr] = newOne; //hack :)

	printf("\nCheltuiala modificata cu succes\n");
}

void UI_sterge_cheltuiala(List* lista) {
	int nr;
	printf("\n STERGERE CHELTUIALA\n");
	nr = UI_getNr_cheltuiala(lista);

	if (nr == -1) {
		return;
	}

	List_deleteElem(lista, nr);

	printf("\nElement eliminat cu succes\n");
}

void UI_vizualizare_lista_filtrat(List* lista) {
	printf("\nFiltreaza dupa: \n");

	printf("1) Numarul apartamentului\n");
	printf("2) Suma\n");
	printf("3) Tipul\n");

	printf("Optiunea ta: ");
	int op;
	scanf("%d", &op);

	switch(op) {
		case 1: UI_vizualizare_lista_filtrat_1(lista); break;
		case 2: UI_vizualizare_lista_filtrat_2(lista); break;
		case 3: UI_vizualizare_lista_filtrat_3(lista); break;
	}

}

void UI_vizualizare_lista_filtrat_1(List* lista) {
	printf("\n Numarul apartamentului: ");
	int nrAp, i, nrAf = 0;
	scanf("%d", &nrAp);
	printf("\n");

	for (i = 0; i < lista->len; ++i) {
		Cheltuiala *c = List_getElem(lista, i);

		if (Cheltuiala_getNrAp(c) == nrAp)
			UI_afiseaza_cheltuiala(c, nrAf++);
	}
}

void UI_vizualizare_lista_filtrat_2(List* lista) {
	printf("\n Suma: ");
	int suma, i, nrAf = 0;
	scanf("%d", &suma);
	printf("\n");

	for (i = 0; i < lista->len; ++i) {
		Cheltuiala *c = List_getElem(lista, i);

		if (Cheltuiala_getSuma(c) == suma)
			UI_afiseaza_cheltuiala(c, nrAf++);
	}
}

void UI_vizualizare_lista_filtrat_3(List* lista) {
	printf("\n Tipul: ");
	int i, nrAf = 0;
	char tip[50];
	scanf("%s", tip);
	printf("\n");

	for (i = 0; i < lista->len; ++i) {
		Cheltuiala *c = List_getElem(lista, i);

		if (strcmp(Cheltuiala_getTip(c), tip) == 0)
			UI_afiseaza_cheltuiala(c, nrAf++);
	}
}

void UI_afiseaza_cheltuiala(Cheltuiala *c, int nrOrd) {
	printf("%d) Nr. ap %d, suma %d, tip %s\n", nrOrd, Cheltuiala_getNrAp(c), Cheltuiala_getSuma(c), Cheltuiala_getTip(c));
}

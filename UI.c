/*
 * UI.c
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "Controller.h"
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
//        case 3: UI_sterge_cheltuiala(lista); break;
//        case 4: UI_vizualizare_lista_filtrat(lista); break;
//        case 5: UI_vizualizare_lista_ordonat(lista); break;

        }
        if (op == 6) break;
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

	Controller_add_apartament(lista, nrAp, suma, tip);

	printf("\nADAUGAT CU SUCCES!\n");
}

void UI_actualizeaza_cheltuiala(List* lista) {
	int nrCheltuieli = lista->len, i, nr;

	if (nrCheltuieli == 0) {
		printf("Nici o cheltuiala in baza de date!\n");
		return;
	}

	printf("\nCheltuieli aflate in baza de date:\n");
	for (i = 0; i < nrCheltuieli; ++i) {
		Cheltuiala *c;
		c = List_getElem(lista, i);
		printf("%d) Nr. ap %d, suma %d, tip %s\n", i, Cheltuiala_getNrAp(c), Cheltuiala_getSuma(c), Cheltuiala_getTip(c));
	}

	printf("\nSelecteaza cheltuiala pe care doresti sa o actualizezi: ");
	scanf("%d", &nr);

	if (nr < 0 || nr >= nrCheltuieli) {
		printf("Numarul cheltuielii invalid\n");
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
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
#include "errors.h"

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
        case 5: UI_vizualizare_lista_ordonat(lista); break;

        }
        if (op == 6) break;
        getch();
    }
}

int UI_Error() {
	if (errno == SUMAERROR) {
		printf("\nSuma trebuie sa fie pozitiva\n");
		return 1;
	}
	if (errno == NRAPERROR) {
		printf("\nNumarul apartamentului trebuie sa fie pozitiv\n");
		return 1;
	}
	if (errno == TIPERROR) {
		printf("\nTip apartamentului trebuie sa fie unul din urmatoarele apa, canal, incalzire, gaz\n");
		return 1;
	}
	return 0;
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

	Controller_adauga_cheltuiala(lista, nrAp, suma, tip);

	if (!UI_Error())
		printf("\nADAUGAT CU SUCCES!\n");
}

int UI_getNr_cheltuiala(List* lista) {
	int nr, nrCheltuieli = lista->len;
	if (nrCheltuieli == 0) {
		printf("Nici o cheltuiala in baza de date!\n");
		return -1;
	}

	printf("\nCheltuieli aflate in baza de date:\n");
	UI_afiseaza_lista(lista);

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

	int sum;
	char* tip;
	tip = malloc(sizeof(char) * 50);
	printf("\nNoua suma: ");
	scanf("%d", &sum);
	printf("Noul tip: ");
	scanf("%s", tip);

	Controller_actualizeaza_cheltuiala(lista, nr, sum, tip);

	if(!UI_Error())
		printf("\nCheltuiala modificata cu succes\n");
}

void UI_sterge_cheltuiala(List* lista) {
	int nr;
	printf("\n STERGERE CHELTUIALA\n");
	nr = UI_getNr_cheltuiala(lista);

	if (nr == -1) {
		return;
	}

	Controller_sterge_cheltuiala(lista, nr);

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
		case 1: UI_vizualizare_lista_filtrat_nrAp(lista); break;
		case 2: UI_vizualizare_lista_filtrat_suma(lista); break;
		case 3: UI_vizualizare_lista_filtrat_tip(lista); break;
	}

}

void UI_afiseaza_lista(List* lista) {
	int i;

	for (i = 0; i < lista->len; ++i) {
		Cheltuiala *c = List_getElem(lista, i);
		UI_afiseaza_cheltuiala(c, i);
	}

}

void UI_vizualizare_lista_filtrat_nrAp(List* lista) {
	printf("\n Numarul apartamentului: ");
	int nrAp;
	scanf("%d", &nrAp);
	printf("\n");

	UI_afiseaza_lista(Controller_getListaFiltrat_nrAp(lista, nrAp));
}



void UI_vizualizare_lista_filtrat_suma(List* lista) {
	printf("\n Suma: ");
	int suma;
	scanf("%d", &suma);
	printf("\n");

	UI_afiseaza_lista(Controller_getListaFiltrat_suma(lista, suma));
}

void UI_vizualizare_lista_filtrat_tip(List* lista) {
	printf("\n Tipul: ");
	char tip[50];
	scanf("%s", tip);
	printf("\n");

	UI_afiseaza_lista(Controller_getListaFiltrat_tip(lista, tip));

}

void UI_afiseaza_cheltuiala(Cheltuiala *c, int nrOrd) {
	printf("%d) Nr. ap %d, suma %d, tip %s\n", nrOrd, Cheltuiala_getNrAp(c), Cheltuiala_getSuma(c), Cheltuiala_getTip(c));
}


void UI_vizualizare_lista_ordonat(List* lista) {
	printf("\nSelecteaza criteriul de ordonare\n");
	printf("1)Suma\n");
	printf("2)Tip\n");
	int op;
	printf("Optiunea ta: ");
	scanf("%d", &op);
	printf("\n");

	switch(op){
		case 1: UI_vizualizare_lista_ordonat_suma(lista); break;
		case 2: UI_vizualizare_lista_ordonat_tip(lista); break;
	}
}

void UI_vizualizare_lista_ordonat_suma(List* lista) {
	UI_afiseaza_lista(Controller_getListaOrd_suma(lista));
}


void UI_vizualizare_lista_ordonat_tip(List* lista) {
	UI_afiseaza_lista(Controller_getListaOrd_tip(lista));
}




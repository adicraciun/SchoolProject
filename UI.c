/*
 * UI.c
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#include <stdio.h>
#include "UI.h"

void UI_start() {
    printf("Bine ai venit in gestionarul de cheltuieli!\n");
    while (1) {
        int op;
        printf("\nMeniu: \n");
        printf("0) Iesi\n");
        printf("1) Adauga cheltuiala noua\n");
        printf("2) Actualizeaza produs\n");
        printf("3) Stergere produs\n");
        printf("4) Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul,apartament)\n");
        printf("5) Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)\n");

        printf("\nOptiunea ta:");
        scanf("%d", &op);

        switch(op) {

        case 1: UI_adauga_cheltuiala(); break;
        case 2: UI_actualizeaza_produs(); break;
        case 3: UI_sterge_produs(); break;
        case 4: UI_vizualizare_lista_filtrat(); break;
        case 5: UI_vizualizare_lista_ordonat(); break;

        }
        if (op == 0) break;
    }
}

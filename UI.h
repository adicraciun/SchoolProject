/*
 * UI.h
 *
 *  Created on: 8 mar. 2016
 *      Author: Korakiun
 */

#ifndef UI_H_
#define UI_H_

#include "List.h"
#include "Cheltuiala.h"

void UI_start(List*);

void UI_adauga_cheltuiala(List*);

void UI_actualizeaza_cheltuiala(List*);

void UI_sterge_cheltuiala(List*);

void UI_vizualizare_lista_filtrat(List*);

void UI_vizualizare_lista_filtrat_1(List* lista);

void UI_vizualizare_lista_filtrat_2(List* lista);

void UI_vizualizare_lista_filtrat_3(List* lista);

void UI_vizualizare_lista_ordonat(List*);

void UI_vizualizare_lista_ordonat_1(List*);

void UI_vizualizare_lista_ordonat_2(List*);

void UI_afiseaza_cheltuiala(Cheltuiala*, int);

#endif /* UI_H_ */

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
#include "Controller.h"

void UI_start(List*);

int UI_Error();

void UI_adauga_cheltuiala(List*);

void UI_actualizeaza_cheltuiala(List*);

void UI_sterge_cheltuiala(List*);

void UI_vizualizare_lista_filtrat(List*);

void UI_vizualizare_lista_filtrat_nrAp(List* lista);

void UI_vizualizare_lista_filtrat_suma(List* lista);

void UI_vizualizare_lista_filtrat_tip(List* lista);

void UI_vizualizare_lista_ordonat(List*);

void UI_vizualizare_lista_ordonat_suma(List*);

void UI_vizualizare_lista_ordonat_tip(List*);

void UI_afiseaza_cheltuiala(Cheltuiala*, int);

void UI_afiseaza_lista(List* lista);

#endif /* UI_H_ */

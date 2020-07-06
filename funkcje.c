#include "funkcje.h"

// push: Dodaj na stos
//
// Funkcja dodaje nową informacje na poczatek listy

void push(stos **lista,int wartosc) {
	stos *pom;

	pom=(stos*) malloc (sizeof(stos));
	pom->dana=wartosc;
	pom->nast=*lista;			
	*lista=pom;
}	// push



// pop: Zdejmij ze stosu
//
// Funkcja ma za zadanie zdejmowac element ze stosu. Zdejmuje go z poczatku
// listy.
// Zwracana wartosc funkcji jest wartoscia zdejmowanego elementu

int pop(stos **lista) {
	stos *wskaz;
	int wartosc;

	if (lista==NULL) 
		fprintf(stderr,"Stos pusty");
	else {
		wartosc=(*lista)->dana;
		wskaz=*lista;
		*lista=(*lista)->nast;
		free(wskaz);
		return wartosc;
	}
} // pop



// empty: Sprawdz czy sa i policz elementy stosu
//
// Funkcja ma za zadanie sprawdzać, czy na stosie sa jakies elementy.
// Gdy takich brak, zwraca 0. W innym przypadku zwraca liczbe elementow

int empty(stos **lista) {
	int licz;
	stos *elem;
	
	if (*lista==NULL)	
		return 0;
	elem=*lista;
	for(licz=0;elem!=NULL;licz++)
		elem=elem->nast;
	return licz;
}	// empty



// print: Drukuj
//
// Funkcja ma za zadanie wypisać na wyjsciu wszystkie elementy stosu.

void print(stos **lista) {
	stos *elem;
	
	elem=*lista;
	while (elem!=NULL) {
		printf("%d ", elem->dana);
		elem=elem->nast;
	}	
	printf("\n");
}	// print

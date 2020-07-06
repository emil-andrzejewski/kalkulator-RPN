/* 														 Emil Andrzejewski 180392											*/
/*																																					*/
/* 															Program KALKULATOR RPN											*/
/*																																					*/
/* Program z zastosowaniem stosu LIFO. Kalkulator obsługiwany w odwrotnej 	*/
/* notacji polskiej (RPN).																									*/
/* Rozmiar tabulatora: 2																										*/
/*																																					*/
/* Opis dzialania programu:																									*/
/* - Podana liczba jest wrzucana na stos																		*/
/* - Podany 1 z operatorow:																									*/
/*		- [+] zdejmuje 2 elementy, wykonuje dodawanie i wrzuca wynik na stos	*/
/*		- [-] zdejmuje 2 elementy, wykonuje odejmowanie i wrzuca wynik na stos*/
/*		- [*] zdejmuje 2 elementy, wykonuje mnożenie i wrzuca wynik na stos		*/
/*		- [/] zdejmuje 2 elementy, wykonuje dzielenie i wrzuca wynik na stos	*/
/*		- [#] usuwa ostatni element ze stosu																	*/
/*		- [$] zamienia miejscami 2 ostatnie elementy na stosie								*/
/*		- [&] duplikuje ostatni element na stowie															*/
/*		- [?] drukuje zawartosc stosu																					*/
/*		- [q] konczy dzialanie programu																				*/
/*																																					*/
/* Informacje dodatkowe:																										*/
/* Program zaczal powstawac 11 stycznia, 12 stycznia dokończyłem pisanie		*/
/* funkcji push, pop, empty i print. Sposob obslugi interfejsu uzytkownieka	*/
/* napisalem 13 stycznia. Drobne poprawki wprowadzone 14 stycznia w czwartek*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "przetwarzaj.h"

int main() {
	stos *lista=NULL;
	int wyjscie=0;

	printf("Podaj dane do kalkulatora do obliczenia\n");
	do {
		przetwarzanie(&lista,&wyjscie);
	} while (wyjscie==0);
	printf("\n	DZIEKUJE ZA WSPOLPRACE :)\n");
	printf("	MILEGO DNIA ZYCZE :)\n\n");
}	// main


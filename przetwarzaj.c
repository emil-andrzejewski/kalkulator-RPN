#include "przetwarzaj.h"


// przetwarzanie: Zarzadzanie kalkulatorem
// 
// PRE:
//		- wczytana liczba musi byc liczba calkowita
//		- przy dzieleniu dzielnik rozny od zera
//		- przy wykonywaniu jakiejs operacji na stosie musza byc min 2 elementy
//
// POST:
//  	-	funkcja ma za zadanie pobierać ze standardowego wejscia liczby, 
//			operatory i opcje wywolan programu. Gdy napotka liczbe liczbe, wrzuca
//			ja na stos.	Gdy spotyka operator: +,-,* lub / to sciaga 2 liczby ze
//			stosu, wykonuje na nich dane dzialanie i wrzuca wynik na stos.
//		- funkcja wczytuje rowniez dane do zarzadzania kalkulatorem: [#] usuwanie
//			ostatniego elementow, [&] duplikowanie ostatniego elementu na stosie,
//			[$] zamiana miejsc ostatnich 2 elementow, [?] wydrukowanie zawartosci
//			stosu na wyjsciu oraz [q] oznaczajace zakonczenie dzialania programu.
		
int przetwarzanie(stos **lista,int *wyjscie) {
	char tab[100]; // tablica pomocnicza
	int i=0,j=0,a,b,c,d, wynik, dodatnia, ujemna;														
	
	while ((c=getchar())!='\n') { // czy napotkano koniec linii
		if (isdigit(c) || c=='-') {	// gdy spotykamy liczbe lub operator "-"
			if (c=='-') {							
				if ((d=getchar())==' ' || d=='\n') {		// samotny znak "-"
					if (empty(lista)<2) {
						fprintf(stderr,"Blad: Za malo elementow na stosie\n");
						break;
					}
					a=pop(lista);													// wykonujemy odejmowanie
					b=pop(lista);
					wynik=b-a;
					printf("%d\n", wynik);
					push(lista,wynik);
				}
				ungetc(d,stdin);
				if (isdigit(c=getchar())) {							// znaleziono liczbe ujemna
					i=0;
					tab[i++]=c;
					while (isdigit(tab[i++]=c=getchar()))
						;	
					tab[i]='\0';
					dodatnia=atoi(tab);			
					ujemna=0-dodatnia;
					push(lista,ujemna);				// wstawienie na stos
				}
			}
			else {									// gdy liczba jest dodatnia
				i=0;
				tab[i++]=c;						// pierwsza cyfra na pocz tablicy
				while (isdigit(tab[i++]=c=getchar()))		//kolejne cyfry do tablicy
					;	
				tab[i]='\0';
				dodatnia=atoi(tab);
				ujemna=0-dodatnia;
				push(lista,dodatnia);
			}			
		}
		switch (c) {		// gdy spotykamy operator oprocz oprocz "-"
			case '+':							// dodawanie
				if (empty(lista)<2) {		// czy przynajmniej 1 element na stosie
					fprintf(stderr,"Blad: Za malo elementow na stosie\n");
					break;
				}
				a=pop(lista);
				b=pop(lista);
				wynik=b+a;
				printf("%d\n", wynik);
				push(lista,wynik);		
				break;
			case '*':							// mnozenie
				if (empty(lista)<2) {
					fprintf(stderr,"Blad: Za malo elementow na stosie\n");
					break;
				}
				a=pop(lista);
				b=pop(lista);
				wynik=b*a;
				printf("%d\n", wynik);
				push(lista,wynik);		
				break;	
			case '/':							// mnozenie
				if (empty(lista)<2) {
					fprintf(stderr,"Blad: Za malo elementow na stosie\n");
					break;
				}
				a=pop(lista);
				if (a==0) {
					fprintf(stderr,"Blad: Nie wolno dzielic przez 0\n");
					push(lista,a);			//wrzucenie zero z powrotem na stos 
					break;
				}
				b=pop(lista);
				wynik=b/a;
				printf("%d\n", wynik);
				push(lista,wynik);		
				break;	
			case '#': 			// usuwanie ostatniego elementu ze stosu
				if (empty(lista)<1) { //gdy brak elementow na stosie
					fprintf(stderr,"Blad: Brak elementow na stosie\n");
					break;
				}
				pop(lista);
				break;
			case '$':				// zamiana 2 ostatnich elementow na stosie
				if (empty(lista)<2) { // gdy mniej niz 2 elementy
					fprintf(stderr,"Blad: Za malo elementow na stosie\n");
					break;
				}
				a=pop(lista);
				b=pop(lista);
				push(lista,a);
				push(lista,b);
				break;
			case '&':				// zduplikowanie ostatniego elementu na stosie
				if (empty(lista)<1) { // gdy brak elementow
					fprintf(stderr,"Blad: Brak elementow na stosie\n");
					break;
				}
				a=pop(lista);
				push(lista,a);
				push(lista,a);
				break;
			case '?':				// wydrukowanie zawartosci stosu
				if (empty(lista)<1) { // gdy stos pusty
					printf("Brak elementow na stosie\n");
					break;
				}
				print(lista);
				break;
			case 'q':			// wyjscie z programu
				*wyjscie=1;
				break;
		}
	}
	return 0;
}	// przetwarzanie


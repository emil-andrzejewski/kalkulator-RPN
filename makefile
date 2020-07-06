kalkulator: main.o funkcje.o przetwarzaj.o
	cc main.o funkcje.o przetwarzaj.o -o kalkulator

main.o: main.c
	cc -c main.c -o main.o

funkcje.o: funkcje.c
	cc -c funkcje.c -o funkcje.o

przetwarzaj.o: przetwarzaj.c
	cc -c przetwarzaj.c -o przetwarzaj.o

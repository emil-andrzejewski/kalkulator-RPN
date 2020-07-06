#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "stack.h"

void push(stos **lista,int wartosc);
int pop(stos **lista);
int empty(stos **lista);
void print(stos **lista);

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
	ps->tos = 0;
}

void push(Stack *ps, int data)
{	
	ps->array[ps->tos] = data;
	++ps->tos;
	
	if (ps->tos == STACKSIZE) {
		fprintf(stdout, "stack is full\n");
		exit(1);
	}
}

int pop(Stack *ps)
{
	if (ps->tos == 0) {
		fprintf(stdout, "stack is emtpy\n");
		exit(2);
	}	
	
	--ps->tos;
	
	return ps->array[ps->tos];
}

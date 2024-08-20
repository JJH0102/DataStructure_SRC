#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size)
{
	ps->pArr = malloc(sizeof(int) * size);
	ps->size = size;
	ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, int data)
{	
	// 1. 예외처리 첫번째 방법
	/*
	if (ps->tos == ps->size) {
		fprintf(stdout, "stack is full\n");
		exit(1);
	}
	*/
	
	// 2. 예외처리 두번째 방법
	assert(ps->tos != ps->size);
	
	ps->pArr[ps->tos] = data;
	++ps->tos;
}

int pop(Stack *ps)
{
	// 1. 예외처리 첫번째 방법
	/*
	if (ps->tos == 0) {
		fprintf(stdout, "stack is emtpy\n");
		exit(2);
	}
	*/
	
	// 2. 예외처리 두번째 방법
	assert(ps->tos != 0);
	
	--ps->tos;
	
	return ps->pArr[ps->tos];
}

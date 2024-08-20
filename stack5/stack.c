#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size, int eleSize)
{
	ps->pArr = malloc(sizeof(eleSize) * size);
	assert(ps->pArr /* != NULL */);	// != NULL 생략 가능
	
	ps->eleSize = eleSize;
	ps->size = size;
	ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, const void *pData)
{	
	assert(ps->tos != ps->size);
	
	// memcpy(&ps->pArr[ps->tos], pData, ps->elseSize);
	memcpy((unsigned char *)ps->pArr + ps->eleSize * ps->tos, pData, ps->eleSize);
	++ps->tos;
}

void pop(Stack *ps, void *pResult)
{
	assert(ps->tos != 0);
	
	--ps->tos;
	
	// memcpy(pResult, &ps->pArr[ps->tos], ps->elseSize);
	memcpy(pResult, (unsigned char *)ps->pArr + ps->eleSize * ps->tos, ps->eleSize);
}

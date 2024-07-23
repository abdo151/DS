#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"Stack.h"

#ifdef LIMITED_MEMORE



void intialize_stack(Stack* ps) {
	ps->top = 0;
}
void push(StackEntry e, Stack* ps) {
	ps->entry[ps->top++] = e;
}
void pop(StackEntry* pe, Stack* ps) {
	*pe = ps->entry[--ps->top];
}
bool stackFull(Stack* ps)  {
	return ps->top == STACKMAXSIZE;
}
bool stackEmpty(Stack* ps) {
	return !ps->top;
}
bool  stackPeek(Stack* ps, StackEntry* pe, int pos) {
	if (ps->top - pos < 0)
		return 0;
	*pe = ps->entry[ps->top - pos];
	return 1;
}
void traverse(Stack* ps, void (pf)(StackEntry)) {
	for (int x = ps->top; x; x--)
		(*pf)(ps->entry[x - 1]);
}
#else

void intialize_stack(Stack* ps) {
    ps->Top = NULL;
    ps->size = 0;
}

void push(StackEntry e, Stack* ps) {
    StackNode* pn = (StackNode*)malloc(sizeof(StackNode));
    if (pn) {
        pn->entry = e;
        pn->Next = ps->Top;
        ps->Top = pn;
        ps->size++;
    }
    else {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
    }
}

void pop(StackEntry* pe, Stack* ps) {
    if (ps->Top) {
        StackNode* pn = ps->Top;
        *pe = pn->entry;
        ps->Top = ps->Top->Next;
        free(pn);
        ps->size--;
    }
    else {
        // Handle pop from empty stack
        printf("Stack is empty\n");
    }
}

void clearStack(Stack* ps) {
    StackNode* pn = ps->Top;
    while (pn) {
        ps->Top = ps->Top->Next;
        free(pn);
        pn = ps->Top;
    }
    ps->size = 0;
}

bool stackEmpty(Stack* ps) {
    return !ps->Top;
}

bool stackFull(Stack* ps) {
    return false;  // A linked list stack is never full (until memory runs out)
}

int stackSize(Stack* ps) {
    return ps->size;
}

void traverseStack(Stack* ps, void(*pf)(StackEntry)) {
    for (StackNode* pn = ps->Top; pn; pn = pn->Next) {
        (*pf)(pn->entry);
    }
}


#endif // LIMITED_MEMORE

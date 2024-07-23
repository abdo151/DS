
#include"General.h"



#define LIMITED_MEMORE

#ifdef LIMITED_MEMORE 
typedef struct stack
{
	int top;
	StackEntry entry[STACKMAXSIZE];
} Stack;

#else
typedef struct stackNode {
    StackEntry entry;
    struct stackNode* Next;
} StackNode;

typedef struct stack {
    StackNode* Top;
    int size;
} Stack;


#endif

void intialize_stack(Stack*);
void push(StackEntry, Stack*);
void pop(StackEntry* , Stack* );
bool stackFull(Stack* );
bool stackEmpty(Stack* );
bool  stackPeek(Stack* ps, StackEntry*, int );
void traverse(Stack* ps, void (pf)(StackEntry));
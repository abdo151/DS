#include"General.h"
#include"Stack.h"
#include"Queue.h"
#include<stdio.h>
#include<iostream>
using namespace std;
#define stackEntry int

int main() {
	stack deg;
	intialize_stack(&deg);
	push(5, &deg);
	push(6, &deg);
	push(7, &deg);
	push(8, &deg);
	push(9, &deg);
	int x;
	for (; !stackEmpty(&deg);) {
		pop(&x, &deg);
		printf("%d\n", x);
	}
	printf("-----------------\ntest Queue\n");
	
	
	Queue degq;
	InitiallyQueue(&degq);
	AppendQueue(5, &degq);
	AppendQueue(6, &degq);
	AppendQueue(7, &degq);
	AppendQueue(8, &degq);
	AppendQueue(9, &degq);
	int xq;
	for (; !QueueEmpty(&degq);) {
		ServeQueue(&xq, &degq);
		cout << xq <<"\n";
	}



}
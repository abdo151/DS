#pragma once
#include"General.h"



#define LIMITED_MEMORE
#ifdef LIMITED_MEMORE // array based imple.

typedef struct  queue
{
	int size, front, rare;
	QueueEntry entry[QUEUEMAXSIZE];
}Queue;

#else //linked based imple.
typedef struct queuenode {
	QueueEntry entry;
	struct queuenode* next;
}QueueNode;

typedef struct queue {
	QueueNode* front, * rare;
	int size;
}Queue;

#endif  


void InitiallyQueue(Queue* pq);
void AppendQueue(QueueEntry e, Queue* pq);
void ServeQueue(QueueEntry* pe, Queue* pq);
void TraverseQueue(Queue* pq, void(*pf)(QueueEntry e));
bool Queuefull(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
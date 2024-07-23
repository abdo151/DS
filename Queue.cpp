#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>


#ifndef  LIMITED_MEMORE
void InitiallyQueue(Queue* pq) {
	pq->front = pq->rare = NULL;
	pq->size = 0;
}

void AppendQueue(QueueEntry e, Queue* pq) {
	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
	if (!pn)
		printf("invalid  memory");
	else {
		pn->entry = e;
		pn->next = NULL;
		if (!pq->rare)
			pq->front = pn;
		else
			pq->rare->next = pn;
		pq->rare = pn;
		pq->size++;
	}

};
void ServeQueue(QueueEntry* pe, Queue* pq) {
	QueueNode* pn = pq->front;
	*pe = pn->entry;
	pq->front = pn->next;
	free(pn);
	if (!pq->front)
		pq->rare = pq->front;
	pq->size--;

};
void TraverseQueue(Queue* pq, void(*pf)(QueueEntry e)) {
	QueueNode* pn;
	for (pn = pq->front; pn; pn = pn->next)
		(*pf)(pn->entry);
};
bool Queuefull(Queue* pq) {
	return 0;
};
bool QueueEmpty(Queue* pq) {
	return !pq->front;
};
int QueueSize(Queue* pq) {
	return pq->size;
};


#else

void InitiallyQueue(Queue* pq)
{
	pq->front = pq->size = 0;
	pq->rare = -1;
}

void AppendQueue(QueueEntry e, Queue* pq)
{
	pq->rare = (pq->rare + 1) % QUEUEMAXSIZE;
	pq->entry[pq->rare] = e;
	pq->size++;
}
void ServeQueue(QueueEntry* pe, Queue* pq)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % QUEUEMAXSIZE;
	pq->size--;
}
void TraverseQueue(Queue* pq, void(*pf)(QueueEntry e))
{
	int pos, s;
	for (pos = pq->front, s = 1; s <= pq->size; s++) {
		(*pf)(pq->entry[pos]);
		pos = (pos + 1) % QUEUEMAXSIZE;
	}
}
bool Queuefull(Queue* pq) {
	return pq->size == QUEUEMAXSIZE;
}
int QueueSize(Queue* pq)
{
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}
#endif // ! LIMITED_MEMORE




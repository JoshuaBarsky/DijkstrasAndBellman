#ifndef PRIORITYQUEUE_H_INCLUDE_
#define PRIORITYQUEUE_H_INCLUDE_

typedef struct PriorityQueue* PriorityQueueRef;

/* Constructors-Destructors */
PriorityQueueRef newPriorityQueue(int n, double* key);
void freePriorityQueue(PriorityQueueRef* pQ);

/*Access functions */
int getNumElements(PriorityQueueRef Q);
int getMin(PriorityQueueRef Q);
int inQueue(PriorityQueueRef Q, int u);

/*Manipulation procedures */
void deleteMin(PriorityQueueRef Q);
void decreaseKey(PriorityQueueRef Q, int u, double k);

/* Other Functions */
void printPriorityQueue(FILE* out, PriorityQueueRef Q);

#endif
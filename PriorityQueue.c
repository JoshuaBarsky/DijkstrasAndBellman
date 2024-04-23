#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <limits.h>
#include <stdio.h>

#include "List.h"
#include "PriorityQueue.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct PriorityQueue{
	int *A;
	int *I;	
	double *key;
	int size;
}PriorityQueue;

void buildHeap(PriorityQueueRef pQ); /*MIN HEAP*/
void heapify(PriorityQueueRef pQ, int n);	/*MIN HEAP*/
void heapSort(PriorityQueueRef pQ); /*MIN HEAP*/
int getLeft(PriorityQueueRef pQ, int n);
int getRight(PriorityQueueRef pQ, int n);
void outputPrint(PriorityQueueRef pQ);
void swap(PriorityQueueRef pQ, int i, int j);

/* Constructors-Destructors */
PriorityQueueRef newPriorityQueue(int n, double* key){
		printf("Making priority queue...\n");
	PriorityQueue *pQ = (PriorityQueue *)malloc(sizeof(PriorityQueue));
	pQ->A = (int *)malloc(n * sizeof(int));
	pQ->I = (int *)malloc(n * sizeof(int));
	assert(pQ!=NULL);
	assert(pQ!=NULL);
	pQ->key = key;
	pQ->size = n;
	
	int i;
	for(i = 0; i < n; i++){
		pQ->A[i] = i+1;
		pQ->I[i] = i+1;
	}
	outputPrint(pQ);
	buildHeap(pQ);
	outputPrint(pQ);
	printf(ANSI_COLOR_GREEN "SUCCESS: Priority queue created as Min Heap!\n\n" ANSI_COLOR_RESET);
	
	return pQ;
}
void freePriorityQueue(PriorityQueueRef* pQ){
	printf("Freeing priority queue...\n");
	if (pQ != NULL && *pQ != NULL){
		free((*pQ)->A);
		free((*pQ)->I);
		free(*pQ);
		*pQ=NULL;
	}
	outputPrint(*pQ);
	printf(ANSI_COLOR_GREEN "SUCCESS: Priority queue freed!\n\n" ANSI_COLOR_RESET);
}

/*Access functions */
int getNumElements(PriorityQueueRef Q){
	if(Q != NULL)
		return Q->size;
	return INT_MIN;
}
int getMin(PriorityQueueRef Q){
	if(Q != NULL)
		return Q->A[0];
	return INT_MIN;
}
int inQueue(PriorityQueueRef Q, int u){
	if(1<=Q->I[u] && Q->I[u]<=getNumElements(Q))
		return 1;
	return 0;
}

/*Manipulation procedures */
void deleteMin(PriorityQueueRef Q){
	if((Q!=NULL) && (getNumElements(Q) >= 1)){
		printf("Deleting min...\n");
		int size_of_arr = getNumElements(Q);
		/*int min = Q->A[1-1];*/
		swap(Q, 1, getNumElements(Q));
		Q->size = Q->size-1;
		buildHeap(Q);
		Q->size = size_of_arr-1;
		outputPrint(Q);
		printf(ANSI_COLOR_GREEN "SUCCESS: Min deleted.\n\n" ANSI_COLOR_RESET);
	}
}

void decreaseKey(PriorityQueueRef Q, int u, double k){
	if(Q!=NULL){
		/*printf("\n\n%d -> %.1f\n",u, Q->key[Q->A[u-1]-1]);*/
		if(k <= Q->key[Q->A[u-1]-1]){
			printf("Decreasing key (%d:%.1f) to (%d, %.1f)...\n", u, Q->key[Q->A[u-1]-1], u, k);
			Q->key[Q->A[u-1]-1] = k;
			/*printf("Key is now %d -> %.1f\n",u, Q->key[Q->A[u-1]-1]);*/
			
			while (u/2 >= 1 && (Q->key[Q->A[(u/2) - 1]-1] > Q->key[Q->A[u-1]-1])){
				/*printf("Swapping: u: %d, u/2: %d\n", u, u/2);*/
				swap(Q, u, u/2);
				u = u/2;
			}
			outputPrint(Q);
			printf(ANSI_COLOR_GREEN"SUCCESS: Key decreased.\n\n"ANSI_COLOR_RESET);
		}
	}
}

/* Other Functions */
void printPriorityQueue(FILE* out, PriorityQueueRef Q){
	
    if (out == NULL) {
        perror("Error opening file");
    }
    if(Q != NULL){
		int i;
		fprintf(out,  "[ ");
		for(i = 0; i < getNumElements(Q); i++){
			fprintf(out, "(%d:%.1f) ", i+1, Q->key[Q->A[i]-1]);
		}
		fprintf(out, " ]\n" );
	}else{
		fprintf(out,  "PRIORITYQUEUE NULL.\n" );
	}

}


int getLeft(PriorityQueueRef pQ, int n){
	if(2*n <= getNumElements(pQ) && (2*n != 0))
		return 2*n;
	else
		return -1;
}

int getRight(PriorityQueueRef pQ, int n){
	if(2*n+1 <= getNumElements(pQ) && (2*n+1 != 1))
		return 2*n + 1;
	else
		return -1;
}

void swap(PriorityQueueRef pQ, int i, int j){	
	if(pQ != NULL){
		int temp_i = pQ->A[i-1];
		int temp_j = pQ->A[j-1];
		
		pQ->A[i-1] = temp_j; /*A[i] = A[j]*/
		pQ->A[j-1] = temp_i; /*A[j] = A[i]*/
		
		
		int temp = pQ->I[pQ->A[i-1]-1];
		pQ->I[pQ->A[i-1]-1] = pQ->I[pQ->A[j-1]-1]; /*I[A[i]] = I[A[j]]*/
		pQ->I[pQ->A[j-1]-1] = temp;	/*I[A[j]] = I[A[i]]*/
		
	}
}

void heapify(PriorityQueueRef pQ, int n){ /*maintain min heap property*/
	int l = getLeft(pQ, n);
	int r = getRight(pQ, n);
	int smallest;
	
	if((l != -1) && ( l <= getNumElements(pQ)) && (pQ->key[pQ->A[l-1]-1] < pQ->key[pQ->A[n-1]-1])){
		smallest = l;
	}
	else
		smallest = n;
	
	if((r != -1) && (r <= getNumElements(pQ)) && (pQ->key[pQ->A[r-1]-1] < pQ->key[pQ->A[smallest-1]-1])){
		smallest = r;
	}
	if (smallest != n){
		swap(pQ, n, smallest);
		heapify(pQ, smallest);
	}else{
	}
	
}

void buildHeap(PriorityQueueRef pQ){ /*produces min heap from unordered array*/
	if(pQ != NULL){
		int i;
		for(i = (getNumElements(pQ)/2); i>0; i--){
			heapify(pQ, i);
		}
	}
}

void heapSort(PriorityQueueRef pQ){ /*sorts an array in place*/
	if(pQ != NULL){
		printf("Sorting array in place from heap...\n");
		buildHeap(pQ);
		int i;
		int size_of_arr = getNumElements(pQ);
		for (i = getNumElements(pQ); i>1; i--){
			swap(pQ, 1, i);
			pQ->size = pQ->size-1;
			heapify(pQ,1);
		}
		pQ->size = size_of_arr;
		outputPrint(pQ);
		printf(ANSI_COLOR_GREEN "SUCCESS: Array sorted in place!\n\n" ANSI_COLOR_RESET);
	}
}

void outputPrint(PriorityQueueRef pQ){
	if(pQ != NULL){
		int i;
		printf(ANSI_COLOR_BLUE "[ ");
		for(i = 0; i < getNumElements(pQ); i++){
			printf("(%d:%.1f) ", i+1, pQ->key[pQ->A[i]-1]);
		}
		printf(" ]\n" ANSI_COLOR_RESET);
	}else{
		printf(ANSI_COLOR_RED "PRIORITYQUEUE NULL.\n" ANSI_COLOR_RESET);
	}
}


/*
I[u] = i -->inverse of rearangement
A[i] = u -->synthetic rearrangement
*/


/*
Code to show array elements:
	int x;
	printf("A: ");
	for(x = 0; x < getNumElements(pQ) ; x++){
		printf("%d ", pQ->A[x]);
	}
	printf("\n");
	printf("I: ");
	for(x = 0; x < getNumElements(pQ) ; x++){
		printf("%d ", pQ->I[x]);
	}
	printf("\n");
	
	printf("exchanging i:%d and smallest:%d..\n", i, j);
*/
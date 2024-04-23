#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <limits.h>
#include "PriorityQueue.h"

int main() {
	printf("-------------------------------------------\n");
	printf("-------------------------------------------\n");
	printf("This program was made by Joshua Barsky.\n");
	printf("March 30, 2024\n");
	printf("-------------------------------------------\n");
	printf("PriorityQueueClient.c started successfully.\n");
	printf("-------------------------------------------\n");
	printf("-------------------------------------------\n");
	
	printf("\n");
	double keys[] = {3.5, 1.2, 6.7, 4.0, 2.3, 5.8, 9.1, 7.4, 8.9, 0.6}; 
	
	PriorityQueueRef Q = newPriorityQueue(sizeof(keys)/sizeof(keys[0]),keys);
	deleteMin(Q);
	decreaseKey(Q, 5, 0.1);
	FILE *fp = fopen("output.txt", "w");
	printPriorityQueue(fp, Q);
	fclose(fp);
	freePriorityQueue(&Q);
	
	printf("\n");
	
	printf("-------------------------------------------\n");
	printf("PriorityQueueClient.c : end of program.\n");
	printf("-------------------------------------------\n");
}
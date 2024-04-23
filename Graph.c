#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <limits.h>
#include"List.h"
#include"Graph.h"
#include "PriorityQueue.h"


/*This program utilizes the List ADT, where a heap has been created with an array.*/

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct Graph{
	ListRef* neighbors; /*Array of neighbors*/
    int* parent; /*Array of parents*/
    int* distance; /*Array of distances*/
    double* weight; /*Array of weights*/
    int order; /*# of vertices*/
    int size; /*# of edges*/
    int source; /*most recent source vertex to either Dijkstra or Bellman Ford*/
}Graph;


/* Constructors-Destructors */
GraphRef newGraph(int n){
	GraphRef G = malloc(sizeof(struct Graph));
	assert(G!=NULL);
	
	G->neighbors = malloc ((n+1) * sizeof(ListRef));
	assert(G->neighbors != NULL);
	
	G->parent = malloc((n+1)*sizeof(int));
	assert(G->parent != NULL);
	
	G->distance = malloc((n+1) * sizeof(int));
	assert(G->distance != NULL);
	
	G->weight = malloc((n + 1) * (n + 1) * sizeof(double));
    assert(G->weight != NULL);
	
    G->order = n; /*# of vertices*/
    G->size = 0; /*# of edges*/
    G->source = 0; 
	return(G);
}
void freeGraph(GraphRef *pG){
	if(pG != NULL && *pG != NULL){
		GraphRef G = *pG;
		int i;
		for (i = 1; i <= getOrder(G); i++)
            freeList(&(G->neighbors[i]));
		free(G->neighbors);
		free(G->parent);
		free(G->distance);
		free(G->weight);
		free(*pG);
		*pG = NULL;
	}
}

/* Access Functions */
int getOrder(GraphRef G){
	return G->order;
}
int getParent(GraphRef G, int u){
	/*add code here*/
	return 0;
}
double getDistance(GraphRef G, int u){
	/*add code here*/
	return 0.0;
}
int getSource(GraphRef G){
	return G->source;
}
void getPath(GraphRef G, int s, int u, ListRef P){
	/*add code here*/
}

/* Manipulation Procedures */
void addDirectEdge(GraphRef G, int u, int v, double w){
	if(u >= 1 && u <= getOrder(G) && v >= 1 && v <= getOrder(G)){
		if(G->neighbors[u] == NULL){
			G->neighbors[u] = newList();
		}
		moveLast(G->neighbors[u]);
		insertAfter(G->neighbors[u], v);
		G->weight[(u * (getOrder(G) + 1)) + v] = w; 
        G->size++;       
	} else {
        printf( ANSI_COLOR_RED"Error: Invalid vertices %d and %d. Values discarded.\n" ANSI_COLOR_RESET, u, v);
    }
}
void Dijkstra(GraphRef G, int s){
	/*add code here*/
}
int BellmanFord(GraphRef G, int s){
	/*add code here*/
	return 0;
}

/* Other Functions */
GraphRef copyGraph(GraphRef G){
	/*add code here*/
	return NULL;
}
void printGraph(FILE* out, GraphRef G){
	/*add code here*/
}
void outputPrintGraph(GraphRef G){	
	int i, j;
	for(i = 0; i < getOrder(G); i++){
		if(G->neighbors[i] != NULL){
			printf( "Neighbors to %d are: [ ", i);
			moveFirst(G->neighbors[i]);
			while (!offEnd(G->neighbors[i])) {
				printf("%d ", getCurrent(G->neighbors[i]));
				moveNext(G->neighbors[i]);
			}
			printf("]\n");
		}
	}
	for (i = 0; i < getOrder(G); i++){
		for (i = 1; i <= getOrder(G); i++) {
        	for (j = 1; j <= getOrder(G); j++) {
            	double weight = G->weight[(i * (getOrder(G) + 1)) + j];
            	if(weight != 0.0)
            		printf("Edge (%d, %d) Weight: %.2f\n", i, j, weight);
        	}
    	}
	}
}
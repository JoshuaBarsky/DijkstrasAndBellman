#ifndef GRAPH_H_INCLUDE_
#define GRAPH_H_INCLUDE_

#include "List.h"
#include "PriorityQueue.h"


typedef struct Graph* GraphRef;

/* Constructors-Destructors */
GraphRef newGraph(int n);
void freeGraph(GraphRef *pG);

/* Access Functions */
int getOrder(GraphRef G);
int getParent(GraphRef G, int u);
double getDistance(GraphRef G, int u);
int getSource(GraphRef G);
void getPath(GraphRef G, int s, int u, ListRef P);

/* Manipulation Procedures */
void addDirectEdge(GraphRef G, int u, int v, double w);
void Dijkstra(GraphRef G, int s);
int BellmanFord(GraphRef G, int s);

/* Other Functions */
GraphRef copyGraph(GraphRef G);
void printGraph(FILE* out, GraphRef G);
void outputPrintGraph(GraphRef G); /*Prints to console*/

#endif
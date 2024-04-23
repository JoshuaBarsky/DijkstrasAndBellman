#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <limits.h>
#include"Graph.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(){
	printf("-------------------------------------------\n");
	printf("-------------------------------------------\n");
	printf("This program was made by Joshua Barsky.\n");
	printf("March 30, 2024\n");
	printf("-------------------------------------------\n");
	printf("GraphClient.c started successfully.\n");
	printf("-------------------------------------------\n");
	printf("-------------------------------------------\n");
	
	printf("Creating empty graph..\n");
	GraphRef G = newGraph(8);
	printf(ANSI_COLOR_GREEN "Graph created.\n" ANSI_COLOR_RESET);
	
	printf("\n");
	
	printf("Source of graph currently is : %d\n", getSource(G));
	
	printf("\n");
	
	printf("Adding direct edge...\n");
	addDirectEdge(G, 1,2,1.0);
	
	addDirectEdge(G, 2,5,1.0);
	addDirectEdge(G, 2,6,1.0);
	addDirectEdge(G, 2,3,1.0);
	
	addDirectEdge(G, 3,4,1.0);
	addDirectEdge(G, 3,7,1.0);
	
	addDirectEdge(G, 4,3,1.0);
	addDirectEdge(G, 4,8,1.0);
	
	addDirectEdge(G, 5,1,1.0);
	addDirectEdge(G, 5,6,1.0);
	
	addDirectEdge(G, 6,7,1.0);
	
	addDirectEdge(G, 7,6,1.0);
	addDirectEdge(G, 7,8,1.0);
	
	addDirectEdge(G, 8,8,1.0);
	

	
	printf(ANSI_COLOR_GREEN "Direct edge added!\n" ANSI_COLOR_RESET);
	
	printf("\n");
	
	printf("Printing graph to console..\n");
	outputPrintGraph(G);
	printf(ANSI_COLOR_GREEN"Graph printed!\n"ANSI_COLOR_RESET);
	
	printf("\n");
	
	printf("Freeing memory of G..\n");
	freeGraph(&G);
	printf(ANSI_COLOR_GREEN"Memory freed.\n"ANSI_COLOR_RESET);
	
	printf("\n");
	
	printf("-------------------------------------------\n");
	printf("GraphClient.c : end of program.\n");
	printf("-------------------------------------------\n");
}
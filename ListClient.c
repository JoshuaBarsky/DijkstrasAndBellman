#include "List.h"

void printListSTDOUT(ListRef L){
	printf("printListSTDOUT() : [");
	moveFirst(L);
	int i = 1;
	for (i=1; i<getLength(L); i++){
		printf("%d, ", getCurrent(L));
		moveNext(L);
	}
	printf("%d]\n", getCurrent(L));
	printf("\t-->Note: the cursor was moved to the end of the list.\n");
}

int main(int argc, char *argv[]) {
	
	printf("----------------------------------------\n");
	printf("----------------------------------------\n");
	printf("This Program Was Created by Joshua Barsky\n");
	printf("March 29, 2024\n");
	printf("----------------------------------------\n");
	printf("ListClient.c : List.h Functionality Test\n");
	printf("----------------------------------------\n");
	printf("----------------------------------------\n");
	printf("\n");
	
	printf("Creating new list...\n");
	ListRef L = newList();
	int i = 1;
	for(i = 1; i<=5; i++){
		insertAfter(L, i);
	}
	for(i = 1; i<=5; i++)
		insertBefore(L, i);
	printListSTDOUT(L);
	printf("New list created.\n");
	
	
	printf("\n");
	
	printf("Checking First and Last values..\n");
	printf("getFirst(L) --> %d\n", getFirst(L));
	printf("getLast(L) --> %d\n", getLast(L));
	
	printf("\n");
	
	printf("List Traversal Test..\n");
	moveFirst(L);
	printf("\tCursor Node: %d\n",getCurrent(L));
	for(i = 1; i<getLength(L); i++){
		moveNext(L);
		printf("\t(. →) Moved Next. Cursor Node: %d\n",getCurrent(L));
	}
	for(i = 1; i<getLength(L); i++){
		movePrev(L);
		printf("\t(← .) Moved Prev. Cursor Node: %d\n",getCurrent(L));
	}
	printf("List Traversal Completed.\n");
	
	printf("\n");
	
	printf("Freeing List..\n");
	freeList(&L);
	printf("List Freed.\n");
	
	printf("\n");
	
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	
	printf("\n");
	
	printf("Creating new list...\n");
	L = newList();
	for(i = 1; i<=5; i++)
		insertAfter(L, i);
	printListSTDOUT(L);
	printf("New list created.\n");
	
	printf("\n");
	
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	
	printf("\n");
	
	insertBeforeCurrent(L, 30);
	printListSTDOUT(L);
	
	movePrev(L);
	movePrev(L);
	movePrev(L);
	
	insertBeforeCurrent(L, 100);
	insertAfterCurrent(L, 100);
	printListSTDOUT(L);
	printf("Length of list: %d\n", getLength(L));
	
	printf("\n");
	
	moveLast(L);
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	
	printf("\n");
	
	printf("Deleting last element..\n");
	deleteLast(L);
	printf("Last element deleted.\n");
	
	printf("\n");
	
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	
	printf("\n");
	
	printListSTDOUT(L);
	printf("Length of list: %d\n", getLength(L));
	
	printf("\n");
	
	moveLast(L);
	deleteCurrent(L);
	printListSTDOUT(L);
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	
	printf("\n");

	
	moveFirst(L);
	
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	deleteCurrent(L);
	printListSTDOUT(L);
	printf("List is empty? : %d \n", isEmpty(L));
	printf("Cursor off list? : %d \n", offEnd(L));
	printf("Cursor at first? : %d \n", atFirst(L));
	printf("Cursor at last? : %d \n", atLast(L));
	
	printf("\n");
	
	printf("Creating A and B..\n");
	
	ListRef A = newList();
	for(i = 1; i<=5; i++)
		insertAfter(A, i);
	
	printf("Length A : %d\n", getLength(A));
	
	ListRef B = newList();
	for(i = 1; i<=5; i++)
		insertAfter(B, i);
	
	printf("Length B : %d\n", getLength(B));
	
	printf("\n");
	
	
	printf("Checking if A and B are the same : %d\n", equals(A,B));
	
	deleteLast(B);
	
	printf("Checking if A and B are the same after delete : %d\n", equals(A,B));
	
	printf("\n");
	
	printf("Checking C = copyList(B)...\n");
	
	ListRef C = copyList(B);
	
	printf("Printing B and C to stdout..\n");
	printListSTDOUT(B);
	printListSTDOUT(C);
	printf("Checking if B and C are the same : %d\n", equals(B,C));
	
	printf("\n");
	
	printf("----------------------------------------\n");
	printf("ListClient.c Functionality Test of List.h concluded.\n");
	printf("----------------------------------------\n");
}



/* Anatomy of a good main function*/

/* main.c */
/* 0 copyright/licensing */
/* 1 includes */
/* 2 defines */
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */
/* 6 function prototypes */

/*int main(int argc, char *argv[]) {*/
/* 7 command-line parsing */
/*}*/

/* 8 function declarations */

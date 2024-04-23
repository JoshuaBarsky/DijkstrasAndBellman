
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <limits.h>
#include "List.h"

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef Node* NodeRef;

typedef struct List{
	NodeRef front;
	NodeRef back;
	NodeRef cursor;
	int length;
} List;


NodeRef newNode(int data){
	NodeRef N = malloc(sizeof(Node));
	assert(N!=NULL);
	N->data = data;
	N->next = NULL;
	N->prev = NULL;
	return(N);
}

void freeNode(NodeRef pN){
	if(pN!=NULL){
		free(pN);
		pN=NULL;
	}
}

/*** Constructors-Destructors ***/
ListRef newList(void){
	ListRef L = malloc(sizeof(List));
	assert(L!=NULL);
	L->front = NULL;
	L->back = NULL;
	L->cursor = NULL;
	L->length = 0;
	return L;
}
void freeList(ListRef* pL){
	if(pL!=NULL && *pL!=NULL){
		makeEmpty(*pL);
		free(*pL);
		*pL=NULL;
	}
}

/*** Access functions ***/
int isEmpty(ListRef L){
	return getLength(L)==0;
}
int offEnd(ListRef L){
	return getCurrent(L) == INT_MIN;
}
int atFirst(ListRef L){
	return L->cursor == L->front;
}
int atLast(ListRef L){
	return L->cursor == L->back;
}
int getFirst(ListRef L){
	if (getLength(L) > 0)
		return L->front->data;
	else
		return INT_MIN;
}
int getLast(ListRef L){
	if (getLength(L) > 0)
		return L->back->data;
	else
		return INT_MIN;
}
int getCurrent(ListRef L){
	if (L->cursor != NULL){
		return L->cursor->data;
	}else{
		return INT_MIN;
	}
}
int getLength(ListRef L){
	return L->length;
}
int equals(ListRef A, ListRef B){
	if(getLength(A) == 0 && getLength(B) == 0)
		return 1;
	if(getLength(A) == getLength(B)){
		moveFirst(A);
		moveFirst(B);
		int i = 1;
		for(i=1; i<=getLength(A); i++){
			if(getCurrent(A)!=getCurrent(B))
				return 0;
		}
		return 1;
	}
	return 0;
}

/*** Manipulation procedures ***/
void makeEmpty(ListRef L){
	while(getLength(L)>0){
		deleteFirst(L);
	}
	L->cursor = NULL;
}
void moveFirst(ListRef L){
	if (getLength(L) > 0)
		L->cursor = L->front;
}
void moveLast(ListRef L){
	if (getLength(L) > 0)
		L->cursor = L->back;
}
void movePrev(ListRef L){
	if(L->cursor != NULL && L->cursor->prev != NULL)
		L->cursor = L->cursor->prev;
	else
		L->cursor = NULL;
}
void moveNext(ListRef L){
	if(L->cursor != NULL && L->cursor->next != NULL)
		L->cursor = L->cursor->next;
	else 
		L->cursor = NULL;
}
void insertBefore(ListRef L, int data){
	NodeRef N = newNode(data);
	if(getLength(L) == 0){
		L->front = N;
		L->back = N;
	}else{
		N->next = L->front;
		N->next->prev = N;
		L->front = N;	
	}
	L->length = L->length+1;
}
void insertAfter(ListRef L, int data){
	NodeRef N = newNode(data);
	if(getLength(L) == 0){
		L->front = N;
		L->back = N;
	}else{
		N->prev = L->back;
		N->prev->next = N;
		L->back = N;	
	}
	L->length = L->length+1;
}
void insertBeforeCurrent(ListRef L, int data){
	if(getLength(L) > 0 && getCurrent(L)!=INT_MIN){
		NodeRef N = newNode(data);
		N->next = L->cursor;
		N->prev = L->cursor->prev;
		
		L->cursor->prev->next = N;
		L->cursor->prev = N;
		
		L->length = L->length+1;
	}
}
void insertAfterCurrent(ListRef L, int data){
	if(getLength(L) > 0 && getCurrent(L)!=INT_MIN){
		NodeRef N = newNode(data);
		N->prev = L->cursor;
		N->next = L->cursor->next;
		
		L->cursor->next->prev = N;
		L->cursor->next = N;
		
		L->length = L->length+1;
	}
}
void deleteFirst(ListRef L){
	if(getLength(L)>0){
		NodeRef N = L->front;
		if(L->cursor == L->front)
			L->cursor = NULL;
		if (getLength(L) > 1){
			L->front = L->front->next;
			L->front->prev = NULL;
		}else{
			L->front = L->back = NULL;
		}
		freeNode(N);
		L->length = L->length-1;
	}
}
void deleteLast(ListRef L){
	if(getLength(L)>0){
		NodeRef N = L->back;
		if(L->cursor == L->back)
			L->cursor = NULL;
		if (getLength(L) > 1){
			L->back = L->back->prev;
			L->back->next = NULL;
		}else{
			L->back = L->front = NULL;
		}
		freeNode(N);
		L->length = L->length-1;
	}
}
void deleteCurrent(ListRef L){
	if(getLength(L)>0){
		NodeRef N = L->cursor;
		if (getLength(L) > 1 && N != L->back && N != L->front){
			N->prev->next = N->next;
			N->next->prev = N->prev;
		}else if(getLength(L) > 1 && N == L->back){
			L->back = N->prev;
			N->prev->next = NULL;
		}else if(getLength(L) > 1 && N == L->front){
			L->front = N->next;
			N->next->prev = NULL;
		}else{
			L->back = L->front = NULL;
		}

		L->cursor = NULL;
		freeNode(N);
		L->length = L->length-1;
	}
}

/*** Other operations ***/
void printList(FILE* out, ListRef L){
	/*insert code*/
}
ListRef copyList(ListRef L){
	ListRef LCopy = newList();
	if(getLength(L) > 0){
		moveFirst(L);
		int i = 1;
		for (i=1; i<=getLength(L); i++){
			insertAfter(LCopy, getCurrent(L));
			moveNext(L);
		}
	}
	return LCopy;
}


/** Optional **/
/*ListRef catList(ListRef A, ListRef B);*/
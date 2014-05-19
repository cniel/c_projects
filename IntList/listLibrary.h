#ifndef LIST_LIBRARY
#define LIST_LIBRARY

#include <stdlib.h>
#include <stdio.h>

/*Structures*/
typedef struct elem elem;
struct elem{
	int val;
	struct elem* next;
};

typedef elem* llist;

/*Prototypes*/
int isEmpty(llist list);
void unshift(llist*, int);
void push(llist*, int);
void displayList(llist);
int shift(llist* list);
int pop(llist* list);
void removeList(llist* list);
llist search(llist list, int value);
int nbOccurences(llist list, int value);
llist isearch(llist list, int value, int i);
int getVal(llist p_elem);
int listLen(llist list);

#endif
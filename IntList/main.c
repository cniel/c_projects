#include<stdlib.h>
#include <stdio.h>

#include "listLibrary.h"

/*Main*/
int main(int argc, char** argv){
	
	int i=0;
	llist maliste = NULL;
	llist p_elem=NULL;

	unshift(&maliste, 1);
	push(&maliste, 2);
	displayList(maliste);
	
	pop(&maliste);
	displayList(maliste);
	
	shift(&maliste);
	displayList(maliste);
	
	pop(&maliste);
	displayList(maliste);
	
	shift(&maliste);
	displayList(maliste);
	
	for(i=10; i>0; i--){
		push(&maliste, i);
		unshift(&maliste, i);
		displayList(maliste);
	}
	
	displayList(maliste);
	
	p_elem = search(maliste, 3);
	displayList(p_elem);
	
	printf("nbOccs de 3 : %d\n", nbOccurences(maliste, 3));
	
	p_elem = isearch(maliste, 3, 2);
	displayList(p_elem);
	p_elem = isearch(maliste, 3, 4);
	displayList(p_elem);
	p_elem = isearch(maliste, 12, 2);
	displayList(p_elem);
	
	removeList(&maliste);
	displayList(maliste);
	
	return 0;
}



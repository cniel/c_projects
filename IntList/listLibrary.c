#include "listLibrary.h"

//ajout en tete
void unshift(llist* list, int value){
	elem* new = NULL;
	new = (elem*)malloc(sizeof(elem));
	if(new == NULL){
		printf("Error malloc.\n");
		EXIT_FAILURE;
	}	
	new->val = value;
	new->next = *list;
	*list = new;
}

//ajout en queue
void push(llist* list, int value){
	elem *new = NULL;
	elem *tmp = *list, *tmp_prec= *list;
	
	while(tmp != NULL){
		tmp_prec = tmp;
		tmp = tmp->next;
	}

	new = (elem*)malloc(sizeof(elem));
	if(new == NULL){
		printf("malloc error.\n");
		EXIT_FAILURE;
	}
	new->val = value;
	new->next=NULL;
	if(isEmpty(tmp_prec)){
		*list = new;
	}else{
		tmp_prec->next = new;
	}
}

//affiche
void displayList(llist list){
	elem* tmp=list;
	
	printf("IntList : [");
	if(isEmpty(list)) printf("Empty");
	while(tmp != NULL){
		printf("%d, ", tmp->val);
		tmp = tmp->next;
	}
	printf("]\n");
}

int isEmpty(llist list){
	if(list == NULL) return 1;
	else return 0;
}

//retire le 1er element
int shift(llist* list){
	elem* tmp = *list;
	if(!isEmpty(tmp)){
		*list = (*list)->next;
		free(tmp);
	}
	
	if(isEmpty(*list)){ 		//empty list now
		*list = NULL;
		return 0;
	}
	return 1;		//or not
}

//retire le dernier element
int pop(llist* list){
	elem* tmp = *list;
	elem* tmp_prec = NULL;
	if(isEmpty(tmp)) return 0;
	if(isEmpty(tmp->next)){
		free(tmp);
		*list = NULL;
		return 0;
	}
	while(tmp->next != NULL){
		tmp_prec = tmp;
		tmp = tmp->next;
	}

	tmp_prec->next=NULL;
	free(tmp);
	return 1;
}

//recherche un element (1e occ)
llist search(llist list, int value){
	while(list != NULL){
		if(list->val == value){
			return list;
		}
		list = list->next;
	}
	return NULL;
}

//nb d'occurences d'un element
int nbOccurences(llist list, int value){
	int c=0;
	while(list != NULL){
		if(list->val == value) c++;
		list = list->next;
	}
	return c;
}

//recherche un element (ieme occ)
llist isearch(llist list, int value, int i){
	int c=0;
	while(list != NULL){
		if(list->val == value){
			c++;
			if(c == i) return list;
		}
		list = list->next;
	}
	return NULL;
}

int getVal(llist p_elem){
	if(isEmpty(p_elem)) return -1;
	else return p_elem->val;
}

int listLen(llist list){
	if(isEmpty(list)) return 0;
	return listLen(list->next)+1;
}

void removeList(llist* list){
	elem *tmp = *list, *tmp2;
	
	while(tmp != NULL){
		tmp2=tmp;
		tmp=tmp->next;
		free(tmp2);
	}
	*list = NULL;
}


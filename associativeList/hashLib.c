#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hnode hnode;
struct hnode{
	struct hnode* next;
	char* key;
	char* value;
};

typedef hnode* hlist;

void alloc_hnode(hnode** p_new, char* key, char* value){
	int keySize=strlen(key);
	int valueSize=strlen(value);
	
	*p_new=(hnode*)malloc(sizeof(hnode));
	if(!*p_new) EXIT_FAILURE;
	(*p_new)->key=NULL; (*p_new)->value=NULL; (*p_new)->next=NULL;
	
	(*p_new)->key = (char*)malloc((keySize+1)*sizeof(char));
	(*p_new)->value = (char*)malloc((valueSize+1)*sizeof(char));
	if(!(*p_new)->key || !(*p_new)->value) EXIT_FAILURE;
	
	strcpy((*p_new)->key, key);
	strcpy((*p_new)->value, value);
}

void clean_hnode(hnode** node){
	(*node)->next=NULL;
	free((*node)->key);
	free((*node)->value);
	free(*node);
}

void disp_hnode(hnode* node){
	printf("%s : %s\n", node->key, node->value);
}

void disp_hlist(hlist mylist){
	hlist tmp=NULL;
	printf("hlist {\n");
	for(tmp=mylist; tmp; tmp=tmp->next){
		printf("\t%s -> %s\n", tmp->key, tmp->value);
	}
	printf("}\n");
}

void assign_hnode(hlist* p_mylist, char* key, char* value){
	hlist tmp;
	//tester si cette 'key' existe déjà
	for(tmp=*p_mylist; tmp; tmp=tmp->next){
		//si oui -> on replace simplement la valeur
		if(strcmp(tmp->key, key) == 0){
			tmp->value = value;
			return;
		}
	}
	
	//si non -> alloc_hnode(new, key, value) + link avec mylist
	hnode* new = NULL;
	alloc_hnode(&new, key, value);
	new->next = *p_mylist;
	*p_mylist = new;
	
}


int main(int argc, char** argv){
	hnode* node=NULL;
	hlist mylist=NULL;
	alloc_hnode(&node, "nom", "valjean");
	disp_hnode(node);
	
	assign_hnode(&mylist, "key", "value");
	assign_hnode(&mylist, "nom", "valjean");
	disp_hlist(mylist);
	
	
	clean_hnode(&node);
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void countDNAbases(char* dna, int* countTab);
void readFasta(char* fileName, char** file_contents);


int main(int argc, char **argv)
{
	int i;
	char* file_contents = NULL;
	int countTab[5] = {0,0,0,0,-1};
	
	readFasta("./dna2.fa", &file_contents);
	countDNAbases(file_contents, countTab);

	for(i=0; i<5; i++){
		printf("%d,\t", countTab[i]);
	}
	
	return 0;
}

void readFasta(char* fileName, char** p_file_contents){
	FILE* handle=NULL;
	size_t file_size=0;

	handle = fopen(fileName, "r");
	if(!handle) EXIT_FAILURE;
	
	fseek(handle, 0, SEEK_END);
	file_size = ftell(handle);
	rewind(handle);
	
	*p_file_contents = (char*)malloc((file_size+1)*sizeof(char));
	if(!*p_file_contents) EXIT_FAILURE;
	fread(*p_file_contents, sizeof(char), file_size, handle); (*p_file_contents)[file_size]=0;
	
	fclose(handle);
	
}


void countDNAbases(char* dna, int* countTab){
	int i;
	
	for(i=0; i<strlen(dna); i++){
			switch(dna[i]){
			case 'A': countTab[0]++; break;	//countTab[0]
			case 'T': countTab[1]++; break;	//countTab[1]
			case 'G': countTab[2]++; break;	//countTab[2]
			case 'C': countTab[3]++; break;	//countTab[3]
			default: countTab[4]++;			//countTab[4]
		}
	}
}

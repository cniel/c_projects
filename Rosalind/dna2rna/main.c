#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void importFile(char* fileName, char** p_file_contents);
void tr(char* str, char in, char out);
void tr2(char* str, char* in, char* out);


int main(int argc, char **argv)
{
	char* file_contents=NULL;
	
	importFile("dna.fa", &file_contents);
	printf("%s\n",file_contents);
	tr2(file_contents, "ATCG", "TAGC");
	printf("%s\n",file_contents);
	
	free(file_contents);
	return 0;
}

//allocate string & import input file in it
void importFile(char* fileName, char** p_file_contents){
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

//replace 1 char by another
void tr(char* str, char in, char out){
	int i;
	
	for(i=0; i<strlen(str); i++){
		if(str[i] == in) str[i]=out;
	}
}

//replace a set of char y another set
void tr2(char* str, char* in, char* out){
	int i, j;
	int inSize=0, outSize=0;
	
	inSize=strlen(in);
	outSize=strlen(out);
	
	if(inSize!=outSize && outSize!=1){
		printf("function tr : string size error.\n");
		EXIT_FAILURE;
	}
	
	//duplicate the loop code : to avoid a test in each passage
	if(outSize==1){
		for(i=0; i<strlen(str); i++){
			for(j=0; j<inSize; j++){
				if(str[i] == in[j]){
					str[i]=*out;
					break;
				}
			}
		}
	}else{
		for(i=0; i<strlen(str); i++){
			for(j=0; j<inSize; j++){
				if(str[i] == in[j]){
					str[i] = out[j];
					break;
				}
			}
		}
	}
}

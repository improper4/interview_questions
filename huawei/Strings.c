#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void StringReverse(char* input, char* output){
	int i;
	char * head;
	char* tmp = malloc(sizeof(char) * strlen(input));
	head = tmp;
	assert(tmp != NULL);
	while(*input != '\0'){
		if(isupper(*input)){
			*(tmp++) = *input;
		}
		input++;
	}
	*tmp = '\0';
	for(i = strlen(head) -1; i >= 0; i--){
		*(output++) = head[i];
	}
	*output = '\0';
}

int main(){
	char* input = "I am A Student!";
	char* output = malloc(sizeof(char) * strlen(input));
	StringReverse(input, output);
	printf("%s\n", output);
}
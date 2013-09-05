#include <stdio.h>
#include <string.h>
#define MAX 2100
char code[MAX];
char buf[MAX];

void hintIt(){
	int i, j, strong = 0, weak = 0;
	int tmp[MAX] = {0};
	int tmp2[MAX] = {0};
	for(i = 0; i < strlen(buf); i++) if(isdigit(buf[i])){
		if(buf[i] == code[i]){
			tmp[i] = 1;
			strong++;
		}
	}

	for(i = 0; i < strlen(buf); i++) if(isdigit(buf[i]) && tmp[i] == 0){
		for(j = 0; j < strlen(code); j++) 
			if(isdigit(code[i]) && tmp[j] == 0 && tmp2[j] == 0){
			if(buf[i] == code[j]){
				weak++;
				tmp2[j] = 1;
				break;
			}
		}
	}
	printf("    (%d,%d)\n",strong, weak);
}
int main(){
	int seqs = 0, start = 0, guess = 0;

	while(fgets(buf, MAX, stdin) != NULL){
		if(buf[strlen(buf) -1] == '\n') buf[strlen(buf) -1] = '\0';

		if(strlen(buf) == 1 && buf[0] == '0') break;
		else if(buf[0] == '0')	{start = 0;guess = 0;}
		else if(guess == 1)	{hintIt();}
		else if(start == 1)	{guess = 1; strcpy(code, buf);}
		else{
			printf("Game %d:\n", ++seqs);
			start = 1;
		}
	}
	return 0;
}
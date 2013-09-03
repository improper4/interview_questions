#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KMAX 21
#define EMAX 72

char keywords[20][KMAX];
char excuses[20][EMAX];
char output[20][EMAX];
int rank[20];

void getWorstExcuses(int k, int e){
	int i, j, max = 0;
	for(i = 0; i < e; i++)	rank[i] = 0;
	char *token;
	static char splits[] = " \t\n,.\"?!&";	
	for(i = 0; i < e; i++)
	for(token = strtok(excuses[i],splits); token != NULL;
		token = strtok(NULL, splits))
		for(j = 0; j < k; j++)
			if(strstr(token , keywords[j]) != NULL){
				rank[i]++;
			}

	for(i = 0; i < e; i++) if(rank[i] > max){
		max = rank[i];
	}
	for(i = 0; i < e; i++) if(rank[i] == max)
		printf("%s\n", output[i]);
}
void modify1(char *str, int len){
	if(str[len -1] == '\n')
		str[len -1] = 0;
}
void modify(char *str, int len, int idx){
	modify1(str,len);
	strcpy(output[idx], str);
	int i;
	for(i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}
int main(){
	int K, E, i, ith = 1;

	while(scanf("%d%d%*c", &K, &E) != EOF){
		char ch;

		for(i = 0; i < K; i++){
			fgets(keywords[i], KMAX, stdin);
			modify1(keywords[i], (int)strlen(keywords[i]));	
		}
		for(i = 0; i < E; i++){			
			fgets(excuses[i], EMAX, stdin);
			modify(excuses[i], (int)strlen(excuses[i]), i);
		}
		printf("Excuse Set #%d\n", ith++);
		getWorstExcuses(K, E);
		printf("\n");
	}
	return 0;
}
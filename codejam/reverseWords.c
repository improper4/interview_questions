#include <stdio.h>
#include <string.h>
#define MAX 1005

int main(){
	int cases;
	int i,j;
	char buf[1005];
	char word[1001][100];
	freopen("B-large-practice.in.txt", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &cases);
	getchar();
	for(i = 0; i < cases; i++){
		fgets(buf, MAX, stdin);
		if(buf[strlen(buf) -1] == '\n')
			buf[strlen(buf) -1] = '\0';
		j = 0;
		char *token;
		for(token = strtok(buf," ");token != NULL;
			token = strtok(NULL, " ")){
			strcpy(word[j++], token);
		}
		int k;
		printf("Case #%d: ", i+ 1);
		for(k = j -1; k >= 0; k--){
			printf("%s ", word[k]);
		}
		printf("\n");
	}
}
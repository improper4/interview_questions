#include <stdio.h>
#include <string.h>

char from[10][100];
char to[10][100];
char text[300];
char backup[300];
void modify(char *str){
	int len = strlen(str);
	if(str[len -1] == '\n')
		str[len -1] = '\0';
}
int main(){
	int rules, i;
	char *tmp;

	while(scanf("%d", &rules) && rules != 0){
		getchar();
		for(i = 0; i < rules; i++){
			fgets(from[i], 100, stdin);
			fgets(to[i], 100, stdin);
			modify(from[i]);modify(to[i]);
		}
		memset(text, 0, 300);
		fgets(text, 300, stdin);
		modify(text);
		for(i = 0; i < rules; i++){
			tmp = strstr(text, from[i]);
			if(tmp != NULL){
				strcpy(backup, tmp+strlen(from[i]));
				strcpy(tmp,to[i]);
				strcat(text, backup); 
				i--;	
			}
		}
		printf("%s\n", text);
	}
	return 0;
}
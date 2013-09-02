#include <stdio.h>
#include <string.h>

void decode(char *str1, int len1, char *str2, int len2){
	static char split[] = ".";
	char *token;
	int i;
	int idx =0;
	int last = 0;
	char strArr[5][100];	
	
	for(i = 0; i < len1; i++){
		if(str1[i] == '<' || str1[i] == '>'){
			memcpy(strArr[idx], str1+ last, i - last +1);
			strArr[idx][i - last] = '\0';
			printf("%s",strArr[idx++]);
			last = i+1;
		}
		if(i == len1 -1){
			memcpy(strArr[idx], str1+ last, i - last +1);
			strArr[idx][i - last+ 1] = '\0';
			printf("%s",strArr[idx]);
		}
	}
	printf("\n");
	token = strtok(str2,split);
	if(token == NULL){
		token = "";
	}
	printf("%s%s%s%s%s\n", token,strArr[3], strArr[2], strArr[1],strArr[4]);

}
void modify(char *str, int len){
	if(str[len -1] == '\n'){
		str[len -1] = 0;
	}
}
int main(){
	int pairs, i;
	freopen("test.txt", "r", stdin);
	scanf("%d",&pairs);
	getchar();
	char buf[pairs * 2][100];

	for(i = 0; i < pairs; i++){
		fgets(buf[2*i], 100, stdin);
		fgets(buf[2*i +1], 100, stdin);
		modify(buf[2* i], strlen(buf[2*i]));
		modify(buf[2* i +1], strlen(buf[2*i +1]));
	}

	for(i = 0; i < pairs; i++){
		decode(buf[2*i], strlen(buf[2*i]),
			buf[2*i +1], strlen(buf[2*i +1]));
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void stringZip(const char* pInputStr, long InputLen, char* pOutputStr){
	int lastChar = *pInputStr;
	int kth = 0;
	int i;
	for(i = 1; i < InputLen +1; i++){
		if(pInputStr[i] == lastChar){
			kth++;
		}else{
			*(pOutputStr++) = lastChar;
			if(kth > 0){
				*(pOutputStr++) = kth + 1 + '0';
			}
			kth = 0;
			lastChar = pInputStr[i];
		}
	}
	*pOutputStr = '\0';
}

int main(){
	const char* a = "kdsfjhsjjjjfhadsjfhkdasddd";
	char* b = malloc(sizeof(char) * strlen(a));
	if(b == NULL)
		return -1;
	stringZip(a, strlen(a), b);
	printf("%s\n", b);
}
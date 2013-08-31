#include <stdio.h>
#include <string.h>
#define MAX 15
char buf[MAX];
int main(){

	while(fgets(buf, MAX, stdin) != NULL){
		if(buf[strlen(buf) -1] == '\n')
			buf[strlen(buf) -1] = '\0';
		int i;
		char tmp = 0;
		for(i = 9; i >= 1; i--){
			if(buf[i] == 'o'){
				tmp |= (i > 6 ) ? (1 << 9 - i ): (1 << (8 -i));
			}
		}
		if(tmp > 0)
			printf("%c",tmp);
		
	}
}
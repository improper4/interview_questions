#include <stdio.h>

int main(){
	int cnt = 1;
	char buf[1000];
	while(fgets(buf, 1000, stdin) != NULL){
		printf("%d: %s\n", cnt++, buf);
	}
	printf("over\n");
}
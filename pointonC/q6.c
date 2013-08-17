#include <stdio.h>
#include <string.h>

void swap(char* c1, char* c2){
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void reverse_string(char *string){
	int i;
	int len = strlen(string);
	printf("%d\n", len);
	for(i = 0; i < len/2; i++){
		printf("%c %c \n", *(string +i), *(string + len - 1 -i));
		swap(string + i, string + len - i -1);
	}
}

int main(){
	char *str = "helloworld!";

	reverse_string(str);
	printf("%s\n", str);
}
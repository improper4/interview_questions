#include <string.h>
#include <stdio.h>
int ascii_to_integer(char *str){
	int len = strlen(str);
	int i, ans;
	ans = 0;
	for(i = 0; i < len; i++){
		ans = ans *10 + (*(str+ i) - '0');
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	char *str = "325848";
	printf("%d\n",ascii_to_integer(str));
	return 0;
}
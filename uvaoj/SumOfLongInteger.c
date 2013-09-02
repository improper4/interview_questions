#include <stdio.h>
#include <string.h>

#define MAX 102
#define ANSMAX 112
char buf[MAX] = {0};
int ans[ANSMAX] = {0};
int main(){
	int canShow = 0;
	int i;
freopen("t.txt", "r", stdin);
	while(fgets(buf, MAX, stdin) != NULL){

		int j = 0, carry = 0, tmp = 0,len = strlen(buf);
		if(buf[0] == '0') break;
		if(buf[len -1] == '\n') buf[len -1] = '\0';

		for(i = strlen(buf) -1; i >= 0; i--){
			tmp = ans[ANSMAX -1 - j]+ buf[i] - '0' + carry;
			ans[ANSMAX -1 -j] = tmp % 10;
			carry = (tmp > 9 ) ? 1: 0;
			j++;
		}
		while(carry == 1){
			tmp = (ans[ANSMAX -1 -j] + carry);
			ans[ANSMAX -1 -j] =  tmp % 10;
			carry = (tmp > 9) ? 1: 0;
			j++;
		}
	}

	for(i = 0; i < ANSMAX; i++){
		if(canShow){ 	printf("%d", ans[i]); continue;}
		if(ans[i] >0)	{canShow = 1; printf("%d", ans[i]);}
	}
	printf("\n");
	return 0;
}
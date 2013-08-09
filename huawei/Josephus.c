#include <stdio.h>
// I changed the input,so this is not a good version.
void josephus(int len, int input[], int m, int output[]){
	int i, j;
	int start = 0;
	int* pOut = output;
	for(i = len; i >0; i--){
		start = (start + m - 1) % i;
		m = input[start];
		*(pOut++) = m;
		for(j = start +1; j < i; j++){
			input[j -1] = input[j];
		}		
	}
}

int main(){
	int i;
	int in[4] = {3,1,2,4};
	int out[4] = {0};
	josephus(4, in, 7, out);
	for(i = 0; i < 4; i++){
		printf("%d ", out[i]);
	}
	printf("\n");
}
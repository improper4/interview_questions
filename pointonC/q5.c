#include <stdio.h>
#include <math.h>

unsigned int reverse_bits(unsigned int val){
	unsigned int ans = 0;
	int i, j;
	
	int bits[32];
	
	for(i = 0; i < 32; i++){
		bits[i] = val & 1;
		val >>= 1;
	}
	for(j = 0,i = 31; i >= 0; j++,i--){
		ans += (1<< j) * bits[i];
	}
	
	/*
	for(i = 1; i != 0; i <<= 1){
		ans <<= 1;
		if(val & 1){
			printf("1");
			ans |= 1;
		}else{
			printf("0");
		}
		j++;
		val >>= 1;

		printf("%u\n", ans);

	}
	printf("\n%d\n", j);
	
	*/
	return ans;
}

int main(){
	printf("reverse_bits: %u\n",reverse_bits(25));
}
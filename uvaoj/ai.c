#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
	int cases;

	scanf("%d",&cases); getchar();
	char buf[1000];
	int k;
	for(k = 0; k < cases; k++){
		fgets(buf, 1000, stdin);
		int len = strlen(buf);
		if(buf[len -1] == '\n'){
			buf[len -1] = '\0';
		}
		int idx= 0, i;
		double U=0, I = 0, P = 0;
		for(i = 0; i < len; i++){
			char c = buf[i];
			if((c == 'P' || c == 'U' || c == 'I') && buf[i+1] == '='){
				int j,dot = 0;
				double tmp = 0,prefix = 1;
				for(j = i+2; j < len; j++){
					char c2 = buf[j];
					if(c2 == '.') 	dot = j; else 
					if(c2 == 'm') 	prefix = 0.001; else 
					if(c2 == 'k')	prefix = 1000; else 
					if(c2 == 'M') 	prefix = 1000000; else 
					if(c2 == 'V' || c2 == 'A' || c2 == 'W') break; else{
						if(dot == 0) tmp = tmp*10 + c2 - '0';
						else	tmp += (c2- '0') * pow(10, dot - j); 
					}
				}
				tmp *= prefix;
				if(c == 'P') P = tmp; else 
				if(c == 'U') U = tmp; else I = tmp;
				if(idx == 0){idx = 1; i = j;}else break;
			}

		}
		printf("Problem #%d\n",k+1);
		if(U == 0) printf("U=%.2lfV\n\n", P/I); else
		if(I == 0) printf("I=%.2lfA\n\n", P/U); else
		printf("P=%.2lfW\n\n", U*I);

	}
	return 0;
}
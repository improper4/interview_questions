#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char* rr;
static char* str;
static int n1, n2;

int match(int c1, int c2){
	if(c2 == n2){
		return c1;	// the char with idx c1 is not matched.
	}
	if(c1 == n1)
		return -1;
	if(rr[c2] == '*'){	// with the longest match.
		int i;
		for(i = n1 -1; i >= c1; i--){
			int ret = match(i, c2+1);
			if(ret != -1)
				return ret;
		}
	}else if(rr[c2] == '?'){
		return match(c1 +1, c2 +1);
	}else if(rr[c2] == str[c1]){
		return match(c1+ 1, c2 +1);
	}
	return -1;
}

void replace(char* src, char* subsrc, char* repl, char* result){
	int i = 0;
	int matchend;
	char* res = result;
	rr = subsrc;
	str = src;
	n1 = strlen(src);
	n2 = strlen(subsrc);
	while(i < n1){
		matchend = match(i, 0);
		if(matchend != -1){
			memcpy(res, repl, strlen(repl));
			res += strlen(repl);
			i += matchend -i;
		}else{
			*(res++) = src[i++];
		}
	}
	*res = '\0';
}
int main(){
	char* src = "abcdefacc";
	char* subsrc = "accs";
	char* repl = "AAAAAAA";
	char* result = malloc(sizeof(char) * 100);
	replace(src, subsrc, repl, result);
	printf("%s\n", result);
}

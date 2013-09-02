#include <stdio.h>
#include <string.h>

static char mirrored[127] = {0};
void init(){
	mirrored['A'] = 'A';
	mirrored['E'] = '3';
	mirrored['J'] = 'L';
	mirrored['H'] = 'H';
	mirrored['I'] = 'I';
	mirrored['J'] = 'L';
	mirrored['M'] = 'M';
	mirrored['O'] = 'O';
	mirrored['S'] = '2';
	mirrored['T'] = 'T';
	mirrored['U'] = 'U';
	mirrored['V'] = 'V';
	mirrored['W'] = 'W';
	mirrored['X'] = 'X';
	mirrored['Y'] = 'Y';
	mirrored['Z'] = '5';
	mirrored['1'] = '1';
	mirrored['2'] = 'S';
	mirrored['3'] = 'E';
	mirrored['5'] = 'Z';
	mirrored['8'] = '8';
	mirrored['0'] = '0';

}
int palindrome(char * buf, int len){
	int i;
	for(i = 0; i < len/2; i++) if(buf[i] != buf[len - 1 -i]){
		if((buf[i] == '0' && buf[len - 1 -i] == 'O')
			|| (buf[i] == 'O' && buf[len - 1 -i] == '0'))
			continue;
		return 0;
	}
	return 1;
}
int mirror(char *buf, int len){
	int i;
	for(i = 0; i < (len+1)/ 2; i++)
		if(mirrored[buf[i]] != buf[len -1 -i]){
			if((buf[i] == '0' && buf[len - 1 -i] == 'O')
				|| (buf[i] == 'O' && buf[len - 1 -i] == '0'))
				continue;
			return 0;
		}
	
	return 1;
}
int main(){
	init();

	char buf[100];
	freopen("test.txt","r", stdin);
	while(scanf("%s", &buf) != EOF){
		
		int len = strlen(buf);

		int ispa = palindrome(buf, len);
		int ismirr = mirror(buf, len);
		if(ispa && ismirr){
			printf("%s -- is a mirrored palindrome.\n", buf);
		}else if(ispa){
			printf("%s -- is a regular palindrome.\n", buf);
		}else if(ismirr){
			printf("%s -- is a mirrored string.\n", buf);
		}else{
			printf("%s -- is not a palindrome.\n", buf);
		}
		printf("\n");
	}
		return 0;
}
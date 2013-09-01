#include <stdio.h>
#include <string.h>
int main(){
	char set[100][50];
	int cases = 0, i, j, cnt = 0,idx = 0;
	int hasPrefix = 0;
	char ch, last = 'A';
	freopen("t.txt", "r", stdin);
	while( (ch=getchar()) != EOF){
		if(ch == '\n'){
			if(last == '9') {last = 'A';continue;}
			set[idx][cnt] = '\0';
			cnt = 0;
			if(!hasPrefix){
				for(i = 0; i < idx; i++){
					printf(" %s || %s\n", set[i], set[idx]);
					for(j = 0; j <11; j++){
						if(set[i][j] == '\0'||set[idx][j] == '\0'){
							hasPrefix = 1;
							break ;
						}
						if(set[i][j] != set[idx][j])
							break;
					}
					if(hasPrefix)
						break;
				}
			}
			idx++;
		}else if(ch == '9'){
			last = '9';
			cases++;
			if(hasPrefix == 0)
				printf("Set %d is immediately decodable\n", cases);
			else
				printf("Set %d is not immediately decodable\n", cases);
			idx = cnt = hasPrefix = 0;
		}else{
			set[idx][cnt++] = ch;

		}
	}
}
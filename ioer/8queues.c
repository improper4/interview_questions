#include <stdio.h>
int ans = 0;
void howMany(int nowth){

	static int line[8] = {0};
	int i,j;
	if(nowth == 8){
		ans++;
		return;
	}
	for(i = 0; i < 8; i++){
		int ok = 1;
		line[nowth] = i;
		for(j = 0; j < nowth; j++){
			if(line[j] == line[nowth] || j - line[j] == nowth - line[nowth] ||
				j + line[j] == nowth + line[nowth]){
				ok = 0;
				break;
			}
		}
		if(ok == 1){
			howMany(nowth +1);
		}
	}
}

int main(){
	howMany(0);
	printf("%d\n", ans);
}
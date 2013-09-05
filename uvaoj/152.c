#include <stdio.h>
#include <math.h>

#define MAXVAL 1000009

int buf[5015][3];
int res[5015] = {MAXVAL};
int ans[10] = {0};
int main(){
	int idx = 0, i,j;
	while(scanf("%d %d %d", &buf[idx][0],&buf[idx][1],&buf[idx][2])){
		if(!buf[idx][0] && !buf[idx][1] && !buf[idx][2])
			break;
		idx++;
	}
	for(i = 0; i < idx; i++){
		int min = MAXVAL;
		for(j = 0; j < i; j++){
			int x = buf[i][0] - buf[j][0];
			int y = buf[i][1] - buf[j][1];
			int z = buf[i][2] - buf[j][2];
			int tmp = x*x + y*y + z*z;
			if(tmp < res[j]) res[j] = tmp;
			if(tmp < min) min = tmp;
		}
		res[i] = min;
	}
	for(i = 0; i < idx; i++){
		int ss = (int) sqrt(res[i]);
		if(ss < 10)
			ans[ss]++;
	}
	for(i = 0; i < 10; i++)
		printf("%4d", ans[i]);
	printf("\n");
	return 0;
}
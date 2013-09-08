#include <stdio.h>
int x[3];
int y[3];
void getSort(int *a, int *b, int *c){
	int tmp;
	if(*a > *b){tmp = *a; *a = *b; *b = tmp;}
	if(*a > *c){tmp = *a; *a = *c; *c = tmp;}
	if(*b > *c){tmp = *b; *b = *c; *c = tmp;}
}
int judgeTrangle(){
	double s1, s2;
	int ans = 0;
	if((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2]))
		return -1;
	if((x[0] == x[1] && y[0] == y[1]) || (x[1] == x[2] && y[1] == y[2]) ||
		(x[0] == x[2] && y[0] == y[2]))
		return -1;
	if(x[1] == x[0] || x[2] == x[0]){
		s1 = (double)(x[1] - x[0])/(double)(y[1]- y[0]);
		s2 = (double)(x[2] - x[0])/(double)(y[2]- y[0]);
	}else{
		s1 = (double)(y[1]- y[0])/(double)(x[1] - x[0]);
		s2 = (double)(y[2]- y[0])/(double)(x[2] - x[0]);
	}
	if(s1 == s2){
		return -1;
	}
	int a = (x[1] -x[0])*(x[1] - x[0]) + (y[1] -y[0])*(y[1]-y[0]);
	int b = (x[2] -x[0])*(x[2] - x[0]) + (y[2] -y[0])*(y[2]-y[0]);
	int c = (x[1] -x[2])*(x[1] - x[2]) + (y[1] -y[2])*(y[1]-y[2]);
	if(a == b || a== c || b== c){
		ans |= 1;
	}
	getSort(&a, &b, &c);
	if(a + b == c){
		ans |= 4;
	}else if( a + b < c){
		ans |= 2;
	}
	return ans;
}
int main(){
	int i, N;
	freopen("t.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d%d%d%d%d%d", x, y, x+1, y+1, x+2, y+2);
		int ans = judgeTrangle();
		printf("Case #%d: ", i+1);
		switch(ans){
			case -1: printf("not a triangle\n");break;
			case 3: printf("isosceles obtuse triangle\n"); break;
			case 5:	printf("isosceles right triangle\n"); break;
			case 1:	printf("isosceles acute triangle\n"); break;
			case 2:	printf("scalene obtuse triangle\n"); break;
			case 4:	printf("scalene right triangle\n"); break;
			case 0:	printf("scalene acute triangle\n");
		}
	}
}
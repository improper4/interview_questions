#include <stdio.h>
int t9[128];

void init(){
	t9['a'] = 2;
	t9['b'] = 22;
	t9['c'] = 222;
	t9['d'] = 3;
	t9['e'] = 33;
	t9['f'] = 333;
	t9['g'] = 4;
	t9['h'] = 44;
	t9['i'] = 444;
	t9['j'] = 5;
	t9['k'] = 55;
	t9['l'] = 555;
	t9['m'] = 6;
	t9['n'] = 66;
	t9['o'] = 666;
	t9['p'] = 7;
	t9['q'] = 77;
	t9['r'] = 777;
	t9['s'] = 7777;
	t9['t'] = 8;
	t9['u'] = 88;
	t9['v'] = 888;
	t9['w'] = 9;
	t9['x'] = 99;
	t9['y'] = 999;
	t9['z'] = 9999;
	t9[' '] = 0;
}
int main(){
	init();
	int N, i;
	char ch;
	int last = 0;
	freopen("C-large-practice.in.txt", "r", stdin);
	freopen("C-small1.out", "w", stdout);
	scanf("%d", &N);
	getchar();
	for(i = 0; i < N; i++){
		printf("Case #%d: ", i+ 1);
		int state = 0;
		while((ch = getchar()) != '\n' && ch != EOF){
			int val = t9[ch];
			if(state && val % 10 == last % 10){
				printf(" ");
			}
			printf("%d", val);
			state = 1;
			last = val;
		}
		printf("\n");
	}

}
#include <stdio.h>
#include <stdlib.h>
static int* tmp;
int cmp(const void* a, const void* b){
	int* aa = (int*) a;
	int* bb = (int*) b;
	if(tmp[*aa] < tmp[*bb]){
		return -1;
	}else if(tmp[*aa] == tmp[*bb]){
		return 0;
	}
	return 1;
}
void simpleschedular(int* task, int len, int* a, int * b){
	int * rank = malloc(sizeof(int) * len);
	int i;
	int c1 = 0, c2 = 0;
	tmp = task;
	for(i = 0; i < len; i++){
		rank[i] = i;
	}
	qsort(rank, len, sizeof(int), cmp);
	for(i = 0; i < len; i++){
		printf("%d ", rank[i]);
	}
	printf("\n");
	for(i = 0; i < len; i++){
		if(task[rank[i]]< 50){
			a[c1++] = rank[i];
		}else if(task[rank[i]] > 50 && task[rank[i]] < 255){
			b[c2++] = rank[i];
		}
	}
	a[c1] = -1;
	b[c2] = -1;
}

int main(){
	int i;
	int task[] = {0, 30, 155, 1, 80, 300, 170, 40, 99};
	int a[5] = {0};
	int b[5] = {0};
	simpleschedular(task, 9,a, b);
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	fflush(NULL);
	for(i = 0; i < 5; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
}


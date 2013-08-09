#include <stdio.h>
void swap(int* arr, int i, int j){
	int tmp =arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int qselect1(int* arr, int from, int to, int k){
	int i;
	int kth = from;
	if(from >= to)
		return k == 1 ? arr[from]: -1;
	for(i = from + 1; i <= to; i++){
		if(arr[from] > arr[i]){
			kth++;
			swap(arr, kth, i);
		}
	}
	swap(arr, from, kth);
	if((kth + 1) == k){
		return arr[kth];
	}else if((kth + 1) > k){
		return qselect1(arr, from, kth -1, k);
	}else{
		return qselect1(arr, kth +1, to, k);
	}
}

int qselect(int* arr, int len, int k){
	return qselect1(arr, 0, len -1, k);
}


int main(){
	int arr[] = {3,4,29,5,12,88,45,36,42,93,22};
	printf("%d\n", qselect(arr, 11, 5));
}
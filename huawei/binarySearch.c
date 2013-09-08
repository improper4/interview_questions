#include <stdio.h>

int binsearch(int* arr, int len, int x){
	int from = 0, to = len -1;
	while(to - from > 1){
		int mid = (from + to)/2;
		if(arr[mid] <= x){
			from = mid;
		}else {
			to = mid;
		}
	}
	return from;
}

int main(){
	int arr[6] = {4,5,12,56,77,88};
	printf("%d\n",binsearch(arr, 6, 13));
}
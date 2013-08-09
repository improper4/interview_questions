#include <stdio.h>
int binsearch1(int* arr, int from, int to, int x){
	int i;
	int mid = (from + to) / 2;
	while(from <= to){
		if(arr[mid] < x){
			return binsearch1(arr, mid +1, to, x);
		}else if(arr[mid] > x){
			return binsearch1(arr, from, mid -1, x);
		}
		return mid;
	}
	return -1;
}

int binsearch(int* arr, int len, int x){
	
	return binsearch1(arr, 0, len -1, x);
}

int main(){
	int arr[6] = {4,5,12,56,77,88};
	printf("%d\n",binsearch(arr, 6, 13));
}
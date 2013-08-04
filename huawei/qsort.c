/*************************************************************************
    > File Name: qsort.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Fri Aug  2 19:48:49 2013
 ************************************************************************/

#include <stdio.h>
void swap(int * arr, int i, int j);
void qsort(int * arr, int from, int to){
	int kth = from;
	int i;
	if(from >= to)
		return;
	for(i = from+ 1; i <= to; i++){
		if(arr[from] > arr[i]){
			kth++;
			swap(arr,i, kth);
		}
	}
	swap(arr, from,kth);
	qsort(arr,from, kth -1);
	qsort(arr, kth+1, to);
}
void swap(int* arr, int i, int j){
	int tmp =arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int main(){
	int i;
	int arr[] = {8,3,12,2,19,4,7,14,1,9};
	qsort(arr,0,9);
	for(i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

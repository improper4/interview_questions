/*************************************************************************
    > File Name: m16.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Fri Jun  7 22:12:08 2013
 ************************************************************************/

#include "m100s.h"

typedef struct MyTreeNode* pMyTreeNode;

struct MyTreeNode{
	int val;
	pMyTreeNode left;
	pMyTreeNode right;
};

pMyTreeNode insertMyTreeNode(int val, pMyTreeNode tr){
	if(tr == NULL){
		tr = malloc(sizeof(struct MyTreeNode));
		IFOUT(tr, 28);
		tr->val = val;
		tr->left = tr->right = NULL;

	}else if(val > tr->val){
		tr->right = insertMyTreeNode(val, tr->right);
	}else if(val < tr->val){
		tr->left = insertMyTreeNode(val, tr->left);
	}
	return tr;
}
void printTree(pMyTreeNode root){
	if(root == NULL)
		return;
	if(root->left != NULL){
		printTree(root->left);
	}
	printf("%d ", root->val);
	if(root->right != NULL){
		printTree(root->right);
	}
}
/*
 *	Queue
 */
typedef struct MyQueue* pMyQueue;
struct MyQueue{
	int uplim;
	int size;
	int front;
	int rear;
	pMyTreeNode* arr;
};
pMyQueue initMyQueue(int uplim){
	pMyQueue q = malloc(sizeof(struct MyQueue));
	IFOUT(q,56);
	q->uplim = uplim;
	q->front = 0;
	q->rear = 1;
	q->size = 0;
	q->arr = malloc(sizeof(pMyTreeNode) * uplim);
	IFOUT(q->arr, 62);
	return q;
}
int isFullOfQueue(pMyQueue q){
	if(q->size == q->uplim)
		return 1;
	return 0;
}
int isEmptyOfQueue(pMyQueue q){
	if(q->size <= 0)
		return 1;
	return 0;
}
void enMyQueue(pMyQueue q, pMyTreeNode node){
	int idx;
	if(isFullOfQueue(q)){
		myerr("QUEUE IS FULL!");
	}
	++q->size;
	idx = q->rear % q->uplim;
	q->arr[idx] = node;
	q->rear = (q->rear + 1) % q->uplim;
}
pMyTreeNode deMyQueue(pMyQueue q){
	if(isEmptyOfQueue(q)){
		myerr("QUEUE IS EMPTY!");
	}
	--q->size;
	q->front = (q->front+ 1) % q->uplim;
	return q->arr[q->front];
}

void layerPrint(pMyTreeNode root){
	
	pMyQueue q = initMyQueue(50);	// just set  50
	enMyQueue(q, root);
	while(!isEmptyOfQueue(q)){
		pMyTreeNode tmp = deMyQueue(q);
		//	print
		printf("%d ", tmp->val);
		if(tmp->left != NULL)	enMyQueue(q, tmp->left);
		if(tmp->right != NULL)	enMyQueue(q, tmp->right);
	}
	printf("\n");
}
int main(){
	int i;
	pMyTreeNode tmp;
	pMyTreeNode root = NULL;
	int d[] = {10, 6, 14, 4, 8, 12, 16};
	for(i = 0; i < 7; i++){
		root = insertMyTreeNode(d[i], root);
	}
	printTree(root);
	printf("\n");
	layerPrint(root);
}

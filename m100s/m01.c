/*************************************************************************
    > File Name: m01.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Mon Jun  3 14:13:19 2013
 ************************************************************************/

#include "m100s.h"
#define MYDBG

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
// this func get a list which is a loop list
//
pMyTreeNode treeTolist2(pMyTreeNode root){
	pMyTreeNode head, tail;
	head = tail = root;
	if(root->left != NULL){
		head = treeTolist2(root->left);
		root->left = head->left;
		head->left->right = root;
	}
	if(root->right != NULL){
		pMyTreeNode tmp = treeTolist2(root->right);
		root->right = tmp;
		tail = tmp->left;
		tmp->left = root; 
	}
	head->left = tail;
	tail->right = head;
	return head;
}
pMyTreeNode treeTolist(pMyTreeNode root){
	pMyTreeNode ans = treeTolist2(root);
	ans->left->right = NULL;
	ans->left = NULL;
	return ans;
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
	// tree to list
	tmp = treeTolist(root);
	while( tmp != NULL){
		printf("%d ", tmp->val);
		tmp = tmp->right;
	}
	printf("\n");
}

/*************************************************************************
    > File Name: m07.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Tue Jun  4 09:26:06 2013
 ************************************************************************/

#include "m100s.h"
typedef struct ListNode* pListNode;
struct ListNode{
	int val;
	pListNode next;
};
pListNode insertNode(pListNode root, int x){
	if(root == NULL){
		root = malloc(sizeof(struct ListNode));
		IFOUT(root, 17);
		root->val = x;
		root->next = NULL;
	}else{
		pListNode tmp = malloc(sizeof(struct ListNode));
		IFOUT(tmp, 22);
		tmp->val = x;
		tmp->next = root->next;
		root->next = tmp;
	}
	
	return root;
}
int isCrox(pListNode a, pListNode b){
	pListNode aEnd, bEnd, tmp;
	tmp = a;
	while(tmp != NULL){
		aEnd = tmp;
		tmp = tmp->next;
	}
	tmp = b;
	while(tmp != NULL){
		bEnd = tmp;
		tmp = tmp->next;
	}
	
	if(bEnd == aEnd)
		return 1;
	return 0;
}

int isCir(pListNode list, pListNode* nodeInLoop){
	pListNode s, s2;
	s = list->next;
	s2 = list->next->next;
	while(s2 != NULL && s2 != s){
		if(s2->next == NULL)
			return 0;
		s2 = s2->next->next;
		s = s->next;
	}
	if(s2 == NULL)
		return 0;
	*nodeInLoop = s;
	return 1;

}

int isCrox2(pListNode a, pListNode b){
	pListNode nodeA, nodeB, tmp;
	int hasCircleA = isCir(a,&nodeA);
	int hasCircleB = isCir(b,&nodeB);


	if(hasCircleA + hasCircleB == 0)	return isCrox(a, b);
	if(hasCircleA + hasCircleB == 1)	return 0;

	tmp = nodeA;
	if(nodeA == NULL){
		printf("nodeA is NULL!\n");
	}
	while(tmp->next != nodeA){
		if(tmp == nodeB){
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int main(){
	pListNode root, root2, crx, end, end2;
	int i;
	root = root2 = NULL;
	root = insertNode(root, 1);
	insertNode(root, 2);
	end = root->next;
	for(i = 3; i < 10; i++){
		insertNode(root, i);
	}
	crx = root->next;
	for(i = 10; i < 20; i++){
		insertNode(root, i);
	}
	root2 = insertNode(root2, 1);
	insertNode(root2, 2);
	end2 = root2->next;
	for(i = 3; i < 6; i++){
		insertNode(root2, i);
	}
	end2->next = crx;
	if(isCrox(root, root2))
		printf("crx\n");

	end->next = crx;

	if(isCrox2(root, root2))
		printf("loop Crx\n");

}

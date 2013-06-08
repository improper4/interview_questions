/*************************************************************************
    > File Name: m24.c
    > Author: improper4
    > Mail: improper4@gmail.com 
    > Created Time: Sat Jun  8 16:11:24 2013
 ************************************************************************/

#include "m100s.h"

typedef struct ListNode* pListNode;
struct ListNode{
	int val;
	pListNode next;
};
pListNode insertListNode(pListNode head, int x){
	if(head == NULL){
		head = malloc(sizeof(struct ListNode));
		IFOUT(head, 18);
		head->val = x;
		head->next = NULL;
	}else{
		pListNode tmp = malloc(sizeof(struct ListNode));
		tmp->val = x;
		tmp->next = head->next;
		head->next = tmp;
	}
	return head;
}
pListNode reverse(pListNode head){
	pListNode last = NULL;
	pListNode tmp = head;
	while(tmp != NULL){
		pListNode next = tmp->next;
		tmp->next = last;
		last = tmp;
		tmp = next;
	}
	return last;
}

int main(){
	int i;
	pListNode ans ;
	pListNode head = NULL;
	head = insertListNode(head, 1);
	for(i = 2; i < 15; i++){
		insertListNode(head, i);
	}
	ans = reverse(head);

	while(ans != NULL){
		printf("%d ",ans->val);
		ans= ans->next;
	}
	printf("\n");
}

#include <stdio.h>
typedef struct Node * pNode;
struct Node{
	int val;
	pNode next;
};
pNode reverse(pNode head){
	pNode p1, p2, p3;
	if(head == NULL || head->next == NULL){
		return head;
	}
	p1 = head;
	p2 = head-> next;
	while(p2 != NULL){
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;
	return head;
}

int main(){
	pNode root = malloc(sizeof(struct Node));
	root->val = 0;
	root->next = NULL;
	

}
/**
 * UVa 548
 * You are to determine the value of the leaf node in a given binary tree that is the terminal 
 * node of a path of least value from the root of the binary tree to any leaf. The value of a 
 * path is the sum of values of nodes along that path.
 * 
 * Input
 * The input file will contain a description of the binary tree given as the inorder and 
 * postorder traversal sequences of that tree. Your program will read two line (until end of 
 * file) from the input file. The first line will contain the sequence of values associated 
 * with an inorder traversal of the tree and the second line will contain the sequence of 
 * values associated with a postorder traversal of the tree. All values will be different, 
 * greater than zero and less than 10000. You may assume that no binary tree will have more 
 * than 10000 nodes or less than 1 node.
 * 
 * Output
 * For each tree description you should output the value of the leaf node of a path of least 
 * value. In the case of multiple paths of least value you should pick the one with the least 
 * value on the terminal node.
 * 
 * Sample Input 
 * 3 2 1 4 5 7 6
 * 3 1 2 5 6 7 4
 * 7 8 11 3 5 16 12 18
 * 8 3 11 7 16 18 12 5
 * 255
 * 255
 * 
 * Sample Output 
 * 1
 * 3
 * 255
 * 
 * @author wade
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inOrder[10001];	
int postOrder[10001];
int minLeaf = 10001;
int minPath = 10000000;
void getLeaf(int faIdx, int from, int to, int sum){
	int i;
	if(from == to){
		if(sum + postOrder[faIdx] < minPath){
			minPath = sum + postOrder[faIdx];
			minLeaf = postOrder[faIdx];
		}
		return;
	}
	for(i = from; i <= to; i++){
		if(inOrder[i] == postOrder[faIdx])
			break;
	}
	if(i == from){
		;
	}else{
		getLeaf(faIdx - (to - i) -1, from, i -1, sum+postOrder[faIdx]);
	}
	if(i == to){
		;
	}else{
		getLeaf(faIdx -1, i+1, to, sum + postOrder[faIdx]);
	
	}
}
int main(){
	int i;
	char *buf = malloc(sizeof(char) * 100000000);
	char* token;
	static char ct[] = " ";
	while(fgets(buf, 100000000, stdin) != NULL){
		int cnt = 0;
		minLeaf = 10001;
		minPath = 10000000;
		for(token = strtok(buf, ct); token != NULL; token = strtok(NULL, ct)){
			inOrder[cnt++] = atoi(token);
		}
		fgets(buf, 100000000, stdin);
		cnt = 0;
		for(token = strtok(buf, ct); token != NULL; token = strtok(NULL, ct)){
			postOrder[cnt++] = atoi(token);
		}
		getLeaf(cnt -1, 0, cnt -1, 0);
		printf("%d\n", minLeaf);
	}
}
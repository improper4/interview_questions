#include <stdio.h>
int doit(int left, char op, int right){
	int res = 0;
	switch(op){
		case '+':
			res = left + right;
			break;
		case '-':
			res = left - right;
			break;
		case '*':
			res = left * right;
			break;
		case '/':
			res = left / right;
			break;
		default:
			res = -1;
	}
	return res;
}
int getTheOpIdx(char* str, int from, int to){
	int i;
	for(i = to -1; i > from; i--)
		if(str[i] == '-' || str[i] == '+')
			return i;
	for(i = to -1; i > from; i--)
		if(str[i] == '*' || str[i] == '/')
			return i;
	return -1;
}
int getValue(char* str, int from, int to){
	int idx, leftVal, rightVal;
	if(to - from == 2)
		return doit(str[from] -48,str[from +1],str[to] - 48);
	
	if(from == to)
		return str[from] - 48;
	idx = getTheOpIdx(str, from, to);
	leftVal = getValue(str,from, idx -1);
	rightVal = getValue(str,idx +1, to);
	return doit(leftVal, str[idx], rightVal);
}
int miniCalc(char* str, int len){
	return getValue(str,0, len -1);
}
int main(){
	char* str = "1+2*3/4+5";
	int res = miniCalc(str, 9);
	printf("%d\n",res);
}
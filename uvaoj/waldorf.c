#include <stdio.h>
#include <string.h>
#include <ctype.h>

char grid[51][51];
int gridRow, gridCol;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, -1, 1};
int match(char *str, int len, int row, int col, int idx){
	int i ,nowRow, nowCol;
	
	for(i = 0; i < len; i++){
		nowRow = row + dy[idx] * i;
		nowCol = col + dx[idx] * i;
		if(nowRow < 0 || nowRow >= gridRow ||
			nowCol < 0 || nowCol >= gridCol)
			return 0;
		if(tolower(str[i]) != grid[nowRow][nowCol]){
			return 0;
		}
	}
	printf("%d %d\n", row +1, col + 1);
	return 1;
}
void matches(char *str, int len){
	int i, j, k;
	for(i = 0; i <gridRow; i++)
	for(j = 0; j < gridCol; j++)
	for(k = 0; k < 8; k++)
		if(match(str, len,i,j,k))
			return;
}
int main(){
	int cases, i;
	int blankLine = 0;

	char what;
	scanf("%d", &cases);


	while(cases > 0){
		if(blankLine > 0){
			printf("\n");
		}
		blankLine = 1;
		cases--;
		char blank;
		

		scanf("%d%d", &gridRow, &gridCol);
		scanf("%c", &what);
		char c;
		for(i = 0; i < gridRow; i++){	
			int j = 0;
			while(scanf("%c", &c), c != '\n'){
				grid[i][j++] = tolower(c);
			}
		}
		int testCase;
		scanf("%d", &testCase);
		char buf[testCase][30];
		for(i = 0; i < testCase; i++){
			scanf("%s",buf[i]);
		}

		for(i = 0; i < testCase; i++){
			matches(buf[i], strlen(buf[i]));
		}
	}
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define WMAX 100
#define CHMAX 210
#define TABLESIZE  2007

char buf[CHMAX];
char* dictWord[5001];
int dictLen = 0;

typedef struct HashTblItem *pH;
struct HashTblItem{
	char * str;
	pH next;
};
pH hashTbl[TABLESIZE] = {NULL};

int hash(char * str){
	unsigned int hashVal = 0;
	while(*str != '\0')
		hashVal = (hashVal << 5) + *(str++);
	
	return hashVal % TABLESIZE;
}
int findItem(char *word, int idx){
	if(hashTbl[idx] == NULL)
		return -1;
	pH tmp = hashTbl[idx];
	
	while(tmp != NULL){
		if(strcmp(word, tmp->str) == 0){
			return 1;
		}
		tmp = tmp->next;
	}
	return -1;
}
void insertToDic(char *word){
	unsigned int idx = hash(word);

	if(findItem(word, idx) == -1){

		pH tmp = hashTbl[idx];
		pH new = malloc(sizeof(struct HashTblItem));
		assert(new != NULL);
		new->str = malloc(sizeof(char) * 100);
		assert(new->str != NULL);
		strcpy(new->str, word);
		dictWord[dictLen++] = new->str;
		hashTbl[idx] = new;
		new->next = tmp;
	}
}
int cmp(const void *a, const void *b){
	return strcmp(*(char**)a,*(char**)b);
}

int main(){
	int i, j;
	char word[WMAX];
	freopen("te.txt", "r", stdin);
	while(fgets(buf, CHMAX, stdin) != NULL){
		if(buf[strlen(buf) -1] == '\n') buf[strlen(buf) -1] = '\0';

		for(i = 0; i < strlen(buf); i++){

			if(isalpha(buf[i])){
				int cnt = 0;
				for(j = i; isalpha(buf[j]);j++){
					word[cnt++] = tolower(buf[j]);
				}
				word[cnt] = '\0';

				insertToDic(word);
				i = j;
			}
			
		}
	}
	qsort(dictWord, dictLen ,sizeof(char*), cmp);
	for(i = 0; i < dictLen ; i++){
		printf("%s\n", dictWord[i]);
	}

}
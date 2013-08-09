#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void number_double(char* input, int time, char* output){
	char *tmpstr;
	char *tmpoutput;
	char * hhhh;
	tmpoutput = output;
	tmpstr = (char*) malloc(1000);
	hhhh = tmpstr;
	if(time == 0){
		strcpy(output, input);
		return;
	}

	if(time == 1|| time == 2){
		while(*input != '\0'){
			if(*input >= '0'&& *input <= '9'){
				*output++ = *input;
				*output++ = *input;
				if(*input != *(input+1)){				
					input++;
				}else{
					input = input + 2;
				}
			}else{
				*output++ = *input;
				input++;
			}
		}
		*output = '\0';
	}

	if(time == 2){
		strcpy(tmpstr, tmpoutput);
		output = tmpoutput;
		while(*tmpstr != '\0'){
			if(*tmpstr >= '0'&& *tmpstr <= '9'){
				*output++ = *tmpstr;
				*output++ = *tmpstr;
				*output++ = *tmpstr;
				*output++ = *tmpstr;
				if(*tmpstr != *(tmpstr+2)){

					tmpstr = tmpstr + 2;
				}else{
					tmpstr = tmpstr + 4;
				}
			}else{
				*output++ = *tmpstr;
				tmpstr++;
			}
		}
		*output = '\0';
	}
	free(hhhh);
}

int main(){
	char* input = "111a2a34";
	char output[100];
	number_double(input, 1, output);
	printf("%s", output);
}
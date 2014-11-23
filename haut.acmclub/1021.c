#include<stdio.h>
#include<string.h>

int main(void){
  int count;
  char line[1000];
  int i;
  
  while(NULL != gets(line)){
	count = 0;
	for(i = 0;line[i];i++){
		switch(line[i]){
			case '(':	count++;
						break;
			case ')':	count--;
						break;
		}
		if(line[i] == 'B')
			line[i + 1] = '\0';
	}
	printf("%d\n",count);
  }
  
  return 0;
}

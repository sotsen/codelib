#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE * fp_input;
	int ch;
	long count = 0;
	char filename[256];
	
	//获取文件名 
	printf("Please enter filename:");
	while(NULL == gets(filename)){
		fprintf(stderr,"Error:Not right filename,input again:"); 
		continue;
	}
	
	//打开文件 
	if((fp_input = fopen(filename,"r")) == NULL){
		fprintf(stderr,"Error:Cannot open \"%s\"\n",filename);
		exit(EXIT_FAILURE);
	}
	
	//计数 
	while((ch = getc(fp_input)) != EOF)
		count++;
	
	//关闭文件 
	if(fclose(fp_input) != 0){
		fprintf(stderr,"Error:Cannot close \"%s\"\n",filename);
		exit(EXIT_FAILURE);
	}
	
	//输出计数结果 
	printf("\"%s\" has %ld characters.\n",filename,count);
	
	return 0;
}

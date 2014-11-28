#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE * fp_input;
	int ch;
	long count = 0;
	char filename[256];
	
	//��ȡ�ļ��� 
	printf("Please enter filename:");
	while(NULL == gets(filename)){
		fprintf(stderr,"Error:Not right filename,input again:"); 
		continue;
	}
	
	//���ļ� 
	if((fp_input = fopen(filename,"r")) == NULL){
		fprintf(stderr,"Error:Cannot open \"%s\"\n",filename);
		exit(EXIT_FAILURE);
	}
	
	//���� 
	while((ch = getc(fp_input)) != EOF)
		count++;
	
	//�ر��ļ� 
	if(fclose(fp_input) != 0){
		fprintf(stderr,"Error:Cannot close \"%s\"\n",filename);
		exit(EXIT_FAILURE);
	}
	
	//���������� 
	printf("\"%s\" has %ld characters.\n",filename,count);
	
	return 0;
}

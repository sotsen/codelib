/* append.c -- �Ѷ���ļ�������׷�ӵ�һ���ļ��� */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 1024
#define SLEN 81

void append(FILE * fp_source,FILE * fp_dest);
void UsageErr(char * ProgFileName);

int main(int argc,char **argv){
	FILE * fp_source,* fp_dest;
	int count;
	
	if(argc < 3)
		UsageErr(argv[0]);
	
	//��Ŀ���ļ� 
	if((fp_dest = fopen(argv[argc-1],"a")) == NULL){
		fprintf(stderr,"Error:Cannot open dest file \"%s\".\n",argv[argc-1]);
		exit(EXIT_FAILURE);
	}
	
	//����������
/*	if(!setvbuf(fp_dest,NULL,_IOFBF,BUFSIZE)){
		fprintf(stderr,"Error:Cannot create output buffer.\n");
		exit(EXIT_FAILURE);
	} 
*/	
	for(count = 1;count < argc-1;count ++){
		//�ж��ļ���
		if(!strcmp(argv[argc-1],argv[count])){
			fprintf(stderr,"Interrupt:Cannot append file to itself.\n");
			continue;
		} 
		
		//��Դ�ļ�
		if((fp_source = fopen(argv[count],"r"))){
			fprintf(stderr,"Error:Cannot open source file \"%s\".\n",argv[count]);
			exit(EXIT_FAILURE);
		}
		
		//׷���ļ�
		append(fp_source,fp_dest);
		
		//�ر��ļ� 
		fclose(fp_source);
		
		//tips 
		printf("info:file \"%s\" appended.\n",argv[count]); 
	}
	
	//�ر�Ŀ���ļ�
	if(!fclose(fp_dest)){
		fprintf(stderr,"Error:Cannot close dest file \"%s\".\n",argv[argc-1]);
		exit(EXIT_FAILURE);
	}
	 
	return 0;
} 

void UsageErr(char * ProFileName){
	fprintf(stderr,"Usage:\t%s  SourceFile1 [SourceFile2] ... DestFile\n",ProFileName);
	exit(EXIT_FAILURE);
}

void append(FILE * fp_src,FILE * fp_dest){
	size_t bytes;
	static char temp[BUFSIZE];
	
	while((bytes = fread(temp,sizeof(char),BUFSIZE,fp_src)) > 0)
		fwrite(temp,sizeof(char),bytes,fp_dest);
}

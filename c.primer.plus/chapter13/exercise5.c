/* append.c -- 把多个文件的内容追加到一个文件中 */

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
	
	//打开目标文件 
	if((fp_dest = fopen(argv[argc-1],"a")) == NULL){
		fprintf(stderr,"Error:Cannot open dest file \"%s\".\n",argv[argc-1]);
		exit(EXIT_FAILURE);
	}
	
	//建立缓冲区
/*	if(!setvbuf(fp_dest,NULL,_IOFBF,BUFSIZE)){
		fprintf(stderr,"Error:Cannot create output buffer.\n");
		exit(EXIT_FAILURE);
	} 
*/	
	for(count = 1;count < argc-1;count ++){
		//判定文件名
		if(!strcmp(argv[argc-1],argv[count])){
			fprintf(stderr,"Interrupt:Cannot append file to itself.\n");
			continue;
		} 
		
		//打开源文件
		if((fp_source = fopen(argv[count],"r"))){
			fprintf(stderr,"Error:Cannot open source file \"%s\".\n",argv[count]);
			exit(EXIT_FAILURE);
		}
		
		//追加文件
		append(fp_source,fp_dest);
		
		//关闭文件 
		fclose(fp_source);
		
		//tips 
		printf("info:file \"%s\" appended.\n",argv[count]); 
	}
	
	//关闭目标文件
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

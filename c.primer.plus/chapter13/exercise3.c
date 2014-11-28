#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){
	FILE * fp_source,* fp_target;
	char ch_copy_buf;
	char filename_source[256],filename_target[256];
	
	//获取文件名并打开文件
	printf("Please input the source filename:");
	while(NULL == (fp_source = fopen(gets(filename_source),"r"))){
		fprintf(stderr,"Error:Cannot open file \"%s\".\n",filename_source);
		printf("Please point another file:");
	} 
	printf("Please input the target filename:");
	while(NULL == (fp_target = fopen(gets(filename_target),"w"))){
		fprintf(stderr,"Error:Cannot open file \"%s\".\n",filename_target);
		printf("Please point another file:");
	}
	
	//复制数据
	while(EOF != (ch_copy_buf = getc(fp_source))){
		if(islower(ch_copy_buf))
			ch_copy_buf = toupper(ch_copy_buf);
		putc(ch_copy_buf,fp_target);
	}
	
	//关闭文件
	if(fclose(fp_source) != 0 || fclose(fp_target) != 0){
		fprintf(stderr,"Error:Cannot close file right.\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
} 

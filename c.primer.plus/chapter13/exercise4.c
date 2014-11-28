#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv){
	int count;
	char ch_disp_buf;
	FILE * fp_source;
	
	if(argc == 1){
		fprintf(stderr,"Eror:Please point a file at least.\n");
		exit(EXIT_FAILURE);
	}
	
	for(count = 1;count < argc;count++){
		//打开文件
		if(NULL == (fp_source = fopen(argv[count],"r"))){
			fprintf(stderr,"Error:Cannot open the %d file:\"%s\".",count,argv[count]);
			exit(EXIT_FAILURE);
		} 
		
		//显示文件内容
		printf("File \"%s\" content:\n\n",argv[count]);
		while(EOF != (ch_disp_buf = getc(fp_source)))
			putc(ch_disp_buf,stdout);
		printf("\n\n\n");
		
		//关闭文件
		if(fclose(fp_source) != 0){
			fprintf(stderr,"Error:Cannot close file \"%s\".",argv[count]);
			exit(EXIT_FAILURE);
		} 
	}	
	
	return 0;
}

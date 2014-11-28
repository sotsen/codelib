#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv){
	FILE *fp_source,*fp_target;
	char buf;
	
	
	//��ȡ�ļ��� 
	if(argc != 3){
		fprintf(stderr,"Usage:%s FileName_Source FileName_Target\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	
	//���ļ� 
	if(NULL == (fp_source = fopen(argv[1],"rb"))){
		fprintf(stderr,"Error:Cannot open source file \"%s\".\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if(NULL == (fp_target = fopen(argv[2],"wb"))){
		fprintf(stderr,"Error:Cannot open target file \"%s\".\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	
	//�����ļ� ,���ֽڶ�д 
	while(1 == fread(&buf,sizeof(char),1,fp_source)){
		fwrite(&buf,sizeof(char),1,fp_target);
	}
	
	//�ر��ļ� 
	if(0 != fclose(fp_source) || 0 != fclose(fp_target)){
		fprintf(stderr,"Error:Cannot close file.\n");
	}
		
	return 0;
}

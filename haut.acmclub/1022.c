/*
��Ŀ����

����ˮ��ʱ������������й��ɣ����ǵ�һ�Σ�ͣһ�£�Ȼ��ζ��Σ�ͣһ�£��ٵ����Σ�ͣһ��...��������һ�����⣺��ƿ��ˮһ����VUL������
ÿһ����D������ÿһ�ε��ٶ���һ�루�������һ�β���D�������򻨷ѵ�ʱ��Ҳ��һ�룩��ͣһ�µ�ʱ��Ҳ��һ����ƿˮʲôʱ���ܹ����أ�

�����ʽ

�������ݰ����������ʵ����ÿ��ʵ��ռһ�У���VUL��D��ɣ����� 0<D<VUL<5000��
*/

#include<stdio.h>
int main(void){
	int vul,d;
	int count;
	int time;
	
	while(2 == scanf("%d%d",&vul,&d)){
		count = 1;
		time = 0;
		
		if(vul%d == 0)
			time += vul/d;
		else
			time += vul/d + 1;
		while(vul > 0){
			if(vul > 0)
				time++;
			vul -= count*d;
			count++;
		}

		printf("%d\n",time-1);
	}
	
	return 0;
}

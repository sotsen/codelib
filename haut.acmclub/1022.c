/*
题目描述

挂盐水的时候，如果滴起来有规律，先是滴一滴，停一下；然后滴二滴，停一下；再滴三滴，停一下...，现在有一个问题：这瓶盐水一共有VUL毫升，
每一滴是D毫升，每一滴的速度是一秒（假设最后一滴不到D毫升，则花费的时间也算一秒），停一下的时间也是一秒这瓶水什么时候能挂完呢？

输入格式

输入数据包含多个测试实例，每个实例占一行，由VUL和D组成，其中 0<D<VUL<5000。
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

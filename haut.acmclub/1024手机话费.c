#include<stdio.h>

int main(void){
	int k,m;
	int days;
	
	while(2 == scanf("%d%d",&m,&k) && m && k){
		days = 0;
		while(m){
			m--;
			days++;
			if(days%k==0)
				days++;
		}
		
		printf("%d\n",days);
	}
	
	return 0;
} 

#include<stdio.h>

int main(void){
	int t,n;
	int min;
	int i,j;
	const int water = 150,cole = 200;
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		min = n;
		for(i = 0;i*water <= n;i++){
			for(j = 0;i*water + j*cole <= n;j++){
				if(n - i*water - j*cole < min)
					min = n - i*water - j*cole;
			}
		}
		for(i = 0;i*cole <= n;i++){
			for(j = 0;i*cole + j*water <= n;j++){
				if(n - i*cole - j*water < min)
					min = n - i*cole - j*water;
			}
		}
		
		printf("%d\n",min);
	}
	
	return 0;
}

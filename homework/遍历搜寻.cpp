#include<stdio.h>
int main()
{
	int a,b,c,x,i,sum=0,e=1;
	scanf("%d%d%d",&a,&b,&c);
	
	if(a>=1&&b>=a&&10000>=b){
		for(x=a;x<b;x++){
			for(i=1;i<x;i++){
				if(x%i==0){
					sum=sum+i;
				}
				else continue; 
			}
			if((x-sum)*(x-sum)<=c*c&&e%5!=0){
				printf("%d	",x);
				e=e+1;
			}
			else if((x-sum)*(x-sum)<=c*c&&e%5==0){
				printf("%d\n",x);
				e=e+1;
			}
			sum=0;
		}
		if(e==1){
			printf("There is no proper number in the interval.");
		}
		if(e%5!=0){
			printf("\n");
		}
	}
	return 0;
}

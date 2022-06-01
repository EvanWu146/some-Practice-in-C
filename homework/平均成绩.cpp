#include<stdio.h>
int main()
{
	int n,i,sum;
	double average;
	scanf("%d",&n);
	char score[n];
	
	for(i=0;i<=n-1;i++) 
		scanf("%d",&score[i]);
	
	for(i=0,sum=0;i<=n-1;i++) 
		sum=sum+score[i];
		
	average=sum;
	average/=n;
	printf("%.2lf\n",average);
	return 0;
	
} 

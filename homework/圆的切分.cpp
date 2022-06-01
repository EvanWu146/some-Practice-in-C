#include<stdio.h>
int main()
{
	int n,s=2,i=1,q;
	scanf("%d",&n);
	if(n==0){
		printf("%d",1);
	}
	if(n>0&&n<100){
		while(i<n){
			i++;
			s=s+i;
		}
		printf("%d",s);
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<n||(i%5!=1||i%6!=5||i%7!=6||i%11!=10);i++);
	printf("%d",i);
	return 0;
} 

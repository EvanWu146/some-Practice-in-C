#include<stdio.h>
int main()
{
	int a,b,max,min;
	
	scanf("%d%d",&a,&b);
	if (a<b)
	{
		max=b;
		min=a;
		printf("The larger number is %d,the smaller number is %d.",max,min);
	}
	if (a>b)
	{
		max=a;
		min=b;
		printf("The larger number is %d,the smaller number is %d.",max,min);
	}
	if(a==b)
	{
		printf("The two numbers are equal.");
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int m,n;
	
	scanf("%d%d",&m,&n);
	if(m+n<=7&&n<=200&&m>=0)
	{
		if(m==3&&n==0)
		{
			printf("A win");
		}
		if(n==3&&m==0)
		{
			printf("B win");
		}
		if((m>3&&n==0)||(n>3&&m==0))
		{
			printf("error");
		}
		if(m>n&&n!=0&&m+n==7)
		{
			printf("A win");
		}
		if(n>m&&m!=0&&m+n==7)
		{
			printf("B win");
		}
		if(m!=0&&n!=0&&m+n<7)
		{
			printf("no result");
		}
		if((m==0&&n<3)||(n==0&&m<3))
		{
			printf("no result");
		}
	}
	if(m+n>7||m<0||n>200)
	{
		printf("error");
	}
	return 0;
}

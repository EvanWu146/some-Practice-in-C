#include<stdio.h>
int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	if(n<100&&n>999)
	{
		printf("The number cannot be changed.");
	}
	else
	{
		if(n%10!=0)
		{
			a=(n-n%100)/100;
	   	    b=((n-a*100)-(n-a*100)%10)/10;
		    c=n-(a*100)-(b*10);
		    n=100*c+10*b+a;
		    printf("%d",n);
		}
		else
		{
			printf("The number cannot be changed.");
		}
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int x,y,i,s;
	
	scanf("%d%d",&x,&y);
	if(y==0)
	{
		s=1;
		printf("%d",s);
	}
	if(y!=0)
	{
		i=2;
		s=x;
		while(i<=y)
		{
			s=s*x;
			i=i+1;
		}
		printf("%d",s);
	}
	return 0;
	
}

#include<stdio.h>
int main()
{
	int n,m,count;
	scanf("%d",&count);
	n=0;
	while(n<count)
	{
		scanf("%d",&m);
		if(m%2==0)
		{
			printf("%d",m);
		}
		n++;
	}
	return 0;
}

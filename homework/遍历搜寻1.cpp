#include<stdio.h>
#include<math.h>
int main() 
{
	int a,b,c,i,j,n,k;
	scanf("%d%d%d",&a,&b,&c);
	j=a;
	n=0;
	k=1;
	while(j<=b)
	{
		for(i=1;i<j;i++)
		{
			if(j%i==0)
			{
				n=n+i;
			}
			else continue;
		}
		if(fabs(j-n)<=c && k%5!=0)
		{
			printf("%d	",j);
			k=k+1;
			
		}
		else if(fabs(j-n)<=c && k%5==0)
		{
			printf("%d	\n",j);
			k=k+1;
		}
		n=0;
		j=j+1;
	}
	if(k<2)
	{
		printf("There is no proper number in the interval."); 
	}
	return 0;
 }


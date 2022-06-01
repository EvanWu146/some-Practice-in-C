#include<stdio.h>
int main()
{
	int n,m,count,a,b,c,d,i;
	scanf("%d%d",&n,&m);
	i=0;
	while(i<=n)
	{
		i++;
		if(i>0&&i<=9&&i/m==i*i)
		{
			printf("%d	",i);
			count++;
			if(count%5==0)
		    {
		    	printf("\n");
			}
		}
		if(i>=10&&i<=99&&i/m==((i-i%10)/10)*((i-i%10)/10)+(i%10)*(i%10))
		{
			printf("%d	",i);
			count++;
			if(count%5==0)
		    {
		    	printf("\n");
			}
		}
		if(i>=100&&i<=999)
		{
			a=(i-i%100)/100;
	   	    b=((i-a*100)-(i-a*100)%10)/10;
		    c=i-(a*100)-(b*10);
		    if(i/m==a*a+b*b+c*c)
		    {
		    	printf("%d	",i);
		    	count++;
		    	if(count%5==0)
		    	{
		    		printf("\n");
				}
			}
		}
		if(i>=1000&&i<=9999)
		{
	        a=(i-i%1000)/1000;
	        b=((i-a*1000)-(i-a*1000)%100)/100;
	        c=((i-a*1000-b*100)-(i-a*1000-b*100)%10)/10;
	        d=i-a*1000-b*100-c*10;
			if(i/m==a*a+b*b+c*c+d*d)
			{
				printf("%d	",i);
				count++;
				if(count%5==0)
				{
					printf("\n");
				}
			}
		}
	}
	return 0;
}

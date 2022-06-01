#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d;
	float x1,x2,y1,y2;
	
	scanf("%f%f%f",&a,&b,&c);
	if(fabs(a-0.0000)<=1e-6)
	{
		printf("The equation is not quadratic.");
	}
	if(fabs(a-0.0000)>=1e-6)
	{
		d=b*b-4*a*c;
		if(fabs(d-0.0000)<=1e-6)
		{
			x1=(-b)/(2*a);
			printf("The equation has two equal roots: %.4f.",x1);
		}
		else if(d>0)
		{
			x1=(sqrt(d)-b)/(2*a);
			x2=(-sqrt(d)-b)/(2*a);
			if(a>0)
			{
				printf("The equation has two distinct real roots: %.4f and %.4f.",x1,x2);
			}
			else
			{
				printf("The equation has two distinct real roots: %.4f and %.4f.",x2,x1);
			}
		}
		else if(d<0)
		{
			y1=(-b)/(2*a);
			y2=sqrt(-d)/(2*a);
			if(a>0)
			{
				printf("The equation has two complex roots: %.4f+%.4fi and %.4f-%.4fi.",y1,y2,y1,y2);
			}
			if(a<0)
			{
				printf("The equation has two complex roots: %.4f-%.4fi and %.4f+%.4fi.",y1,y2,y1,y2);
			}
		}
	}
	return 0;
}

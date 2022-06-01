#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	
	if(fabs((c-d*0.2)-0.000000)<=1e-6)
	{
		printf("infinite.");
	}
	else
	{
		printf("%.2lf",a * b / ( c - d * 0.2 ));
	}
	return 0;
}

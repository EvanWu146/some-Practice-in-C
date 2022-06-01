#include<stdio.h>
int main()
{
	double a,b,c,d;
	double e;
	
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	e=(a+b)*(a-b)+c/d;
	printf("%lf",e);
	return 0;
}

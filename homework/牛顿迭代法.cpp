#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	double x; 
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x=1.000000;
	do{
		x=x-(a*x*x*x+b*x*x+c*x+d)/(3*a*x*x+2*b*x+c);
	}
	while(fabs((a*x*x*x+b*x*x+c*x+d)/(3*a*x*x+2*b*x+c))>1e-5);
	printf("%lf\n",x);
	return 0;
}

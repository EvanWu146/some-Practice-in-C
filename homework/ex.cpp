#include<stdio.h>
#include<math.h>
int main(void)
{
	double x,s,p,i;
	scanf("%lf",&x);
	i=1.000000;
	s=1.000000;
	p=1.000000;
	while(fabs(s)>=1e-8){
		s=s*x/i;
		p=p+s;
		i++;
	}
	
	printf("%.4lf\n",p);
	return 0;
}

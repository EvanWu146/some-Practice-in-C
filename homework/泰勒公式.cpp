#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	double x;
	double m,p;
	
	scanf("%lf",&x);
	i=1;
	do{
		if(i==1){
			p=x;
		}
		else{
			m=p*(-1)*x*x/((2*i-1)*(2*i-2));
			p=m+p;
		}
		i++;
	}
	while(fabs(m)<=1e-6);
	printf("sin(%lf)=%lf",x,p);
	return 0;
} 

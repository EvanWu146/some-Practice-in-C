#include<stdio.h>;
#include<math.h>
int main()
{
	int a,b,c;
	double S,Area;
	
	scanf("%d%d%d",&a,&b,&c);
	if((a+b>c)&&(b+c>a)&&(a+c>b))
	{
		S=(a+b+c)/2.0;
		Area=sqrt(S*(S-a)*(S-b)*(S-c));
		printf("%.3lf",Area);
	}
	else
    {
		printf("The egdes cannot make up of a triangle.");
	}
	return 0;
}

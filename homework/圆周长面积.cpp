#include<stdio.h>;
int main()
{
	double R,C,S;
	const double PI=3.14159265;
	
	scanf("%lf",&R);
	C=2*PI*R;
	S=PI*R*R;
	printf("The perimeter is %.4lf, the area is %.4lf.\n",C,S);
	return 0;
	
}

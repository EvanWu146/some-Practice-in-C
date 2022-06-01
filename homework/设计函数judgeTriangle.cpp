#include<stdio.h>
int main()
{
	int a;
	int b;
	int c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c&&b+c>a&&a+c>b){
		if(a*a+b*b==c*c||a*a==b*b+c*c||b*b==c*c+a*a){
			printf("It is a right-angled triangle.");
		}
		else if((a==b&&b!=c)||(a==c&&a!=b)||(b==c&&b!=a)){
			printf("It is an isosceles triangle.");
		}
		else if(a==b&&b==c){
			printf("It is a equilateral triangle.");
		}
		else{
			printf("It is a scalenous triangle.");
		}
	}
	else{
		printf("It is not a triangle.");
	}
}

#include<stdio.h>
int main()
{
	int a,b,c,d,i;
	scanf("%d",&i);
	a=(i-i%1000)/1000;
	b=((i-a*1000)-(i-a*1000)%100)/100;
	c=((i-a*1000-b*100)-(i-a*1000-b*100)%10)/10;
	d=i-a*1000-b*100-c*10;

	printf("%d",a+b+c+d);
	return 0;
} 

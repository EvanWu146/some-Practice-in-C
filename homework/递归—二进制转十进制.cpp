#include<stdio.h>
int convert(int);
main()
{
	long int n;
	scanf("%ld",&n);
	printf("%d",convert(n));
}
int convert(int x)
{
	if(x==0||x==1){
		return x;
	}
	else{
		return x%10+convert(x/10)*2;
	}
}

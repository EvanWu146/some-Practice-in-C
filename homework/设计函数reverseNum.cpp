#include<stdio.h>
int reverse(int);
main()
{
	int n;
	scanf("%d",&n);
	printf("The reverse form of number %d is %d.",n,reverse(n));
}
int reverse(int n)
{
	int m;
	m=0;
	while(n!=0){
		m=m*10+n%10;
		n=n/10;
	}
	return m;
}

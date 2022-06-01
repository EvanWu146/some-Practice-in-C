#include<stdio.h>
int getDigit(long long int);
main()
{
	long long int n;
	scanf("%lld",&n);
	if(getDigit(n)==1)
		printf("The integer %lld has %lld digit.",n,getDigit(n));
	if(getDigit(n)!=1)
		printf("The integer %lld has %lld digits.",n,getDigit(n));
}
int getDigit(long long int n)
{
	int i=0;
	while(n!=0){
		n=n/10;
		i=i+1;
	}
	return i;
} 

#include<stdio.h>
int reverse(int);
main()
{
	long int x;
	scanf("%ld",&x);
	if(x%10==0||x!=reverse(x)){
		printf("No");
	}
	if(x%10!=0&&x==reverse(x)){
		printf("Yes");
	}	
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

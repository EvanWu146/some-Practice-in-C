#include<stdio.h>
long long int mypow(int,int);
main()
{
	int x,n;
	scanf("%d%d",&x,&n);
	printf("%lld",mypow(x,n));
}
long long int mypow(int x,int n)
{
	int i=0;
	long long int p=1;
	if(n==i){
		return 1;
	}
	else{
		while(i<n){
			p=x*p;
			i++;
		}
		return p;
	}
}

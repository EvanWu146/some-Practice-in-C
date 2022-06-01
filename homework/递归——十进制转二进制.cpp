#include<stdio.h>
long long int convert(long long int);
main()
{
	long long int n;
	long long int l,t=1;
	scanf("%lld",&n);
	l=convert(n)/10;
	while(l!=0){
		l=l/10;
		t++;
	}
	printf("%d",t);
}
long long int convert(long long int x)
{
	if(x==0||x==1){
		return x;
	}
	else{
		return x%2+convert(x/2)*10;
	}
}

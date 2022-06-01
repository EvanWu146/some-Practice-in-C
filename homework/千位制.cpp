#include<stdio.h>
int main()
{
	long int n,T,n1,n2;
	scanf("%ld",&n);
	int len=0;
	T=n;
	while(T!=0){
		T=T/10;
		len++;
	}
	
	int j=1,k;
	long int x;
	int len1=len;
	while(len>1){
		for(x=1,k=1;k<len;x=x*10,k++);
		T=n/x;
		printf("%d",T);
		n=n%x;
		if((len1-j)%3==0){
			printf(",");
		}
		j++;
		len--;
	}
	printf("%d",n);
	return 0;
}

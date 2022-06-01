#include<stdio.h>
int main()
{
	long long int a,b,m,o,s,c;
	int n,i;
	scanf("%d",&n);
	
	i=1;
	a=1;
	b=3;
	if(n%2!=0){
		while(i<n){
			s=(i+4)*b;
			a=b*(i+2)+a*(i+4);
			b=s;
			if(a>b){
			o=a;
			m=b;
			c=o%m;
			while(c!=0){
				o=m;
				m=c;
				c=o%m;
			}
			a=a/m;
			b=b/m;
			}
			i=i+2;
		}
		printf("%lld/%lld",a,b);
	}
	return 0;
}

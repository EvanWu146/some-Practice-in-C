#include<stdio.h>
int main()
{
	int n,i,q,u,A,B,s;
	scanf("%d",&n);
	if(n%2==0&&n>=4){
		for(i=2;i<=n/2;i++){
			q=n-i;
			s=2;
			if(i==2){
				A=1;
			}
			else{
				while(s<i){
					A=i%s;
					s++;
					if(A==0){
						break;
					}
				}
			}
			for(u=2;u<q;u++){
				if(q%u==0){
					B=0;
					break;
				}
				else{
					B=1;
				}
			}
			if(A!=0&&B!=0){
				printf("%d and %d\n",i,q);
			}
		}

		
	}
	return 0;
}

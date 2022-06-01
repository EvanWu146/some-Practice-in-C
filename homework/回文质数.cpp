#include<stdio.h>
int isreverse(int);
int isprim(int);
main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++){
		if(isreverse(i)==1){
			if(isprim(i)){
				printf("%d\n",i);
			}
		}
	}
	return 0;
}
int isreverse(int n){
	int m=0;
	int N;
	N=n;
	while(n!=0){
		m=m*10+n%10;
		n=n/10;
	}
	if(m==N){
		return 1;
	}
	else return 0;
}
int isprim(int x){
	int j,y=1;
	for(j=2;j<=x/2;j++){
		if(x%j==0){
			y=0;
		}
	}
	if(y==0){
		return 0;
	}
	else return 1;
}

#include<stdio.h>
#include<math.h>
float y(int,float);
main()
{
	int n;
	float x;
	int T,t=1;
	scanf("%d",&T);
	while(t<=T){
		scanf("%d%f",&n,&x);
		printf("%.3f\n",y(n,x));
		t++;
	}
} 
float y(int a,float b){
	if(a==1){
		return sqrt(b+a);
	}
	else{
		return sqrt(y(a-1,b)+a);
	}
}

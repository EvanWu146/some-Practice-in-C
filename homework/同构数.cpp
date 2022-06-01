#include<stdio.h>
int main()
{
    int x,t,r,i;
    scanf("%d",&x);
    r=x*x;
    i=0;
    t=10;
    if(x>=1&&x<=10000){
    	while(i!=x&&(r-i)%t!=0){
    		i=(r-i)%t+i;
    		t=t*10;
		}
		if(i==x){
			printf("Yes");
		}
		else{
			printf("No");
		}
	}
	else{
		printf("%d out of range",x);
	}
    return 0; 
}


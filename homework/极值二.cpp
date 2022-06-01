#include<stdio.h>
int main()
{
	int n,a,i;
	int max,min;
	
	while(scanf("%d",&n),n!=0){
		i=1;
		max=0;
		while(i<=n){
			scanf("%d",&a);
			if(max==0){
				max=a;
				min=a;
			}
			if(max!=0){
				if(a<max){
					if(a<min){
						min=a;
					}
					if(a>=min){
						min=min;
					}
				}
				if(a>=max){
					max=a;
				}
			}
			i=i+1;
		}
    if((max+min)%2==0){
	    printf("%d %d",min,max);
	}
		
	}
	return 0;
}

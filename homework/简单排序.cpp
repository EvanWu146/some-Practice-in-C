#include<stdio.h>
int main()
{
	int n,i,flag,front,g=0;
	int input[1000];
	scanf("%d",&n);
	
	for(i=0;i<=n-1;i++){
		scanf("%d",&input[i]);
	}
	for(g=1;g<=n-1;g++){
		for(i=1,front=input[0];i<=n-1;i++){
			if(input[i]<front){
				input[i-1]=input[i];
				input[i]=front;
			} 
			front=input[i];	
		}
	}
	for(i=0;i<=n-1;i++){
		printf("%d ",input[i]);
	}
}

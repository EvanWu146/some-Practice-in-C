#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int A[n],B[n];
	int i,mid;
	
	for(i=0;i<=n-1;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<=n-1;i++){
		scanf("%d",&B[i]);
	}
	
	for(i=0;i<=n-1;i++){
		mid=A[i];
		A[i]=A[B[i]];
		A[B[i]]=mid;
		
		
	}
	
	for(i=0;i<=n-1;i++){
		printf("%d",A[i]);
		if(i==n-1){
			printf("\n");
		}
		else{
			printf(" ");
		}
	}

} 

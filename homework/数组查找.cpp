#include<stdio.h>
int main()
{
	int n,m,i,j,flag;
	
	scanf("%d",&n);
	int store[n];
	for(i=0;i<=n-1;i++){ 
		scanf("%d",&store[i]);
	} 
	
	scanf("%d",&m);
	int search[m];
	for(i=0;i<=m-1;i++){ 
		scanf("%d",&search[i]);
	} 
	
	 
	for(i=0;i<=m-1;i++){/*查找的数*/ 
		flag=0;
		if(n==1) printf("NULL\n");
		else {
		
			for(j=0;j<=n-1;j++){/*原有存储的数*/ 
		
				if(j==0&&store[j]==search[i]){
					printf("%d",store[j+1]);
				}
				else if(j!=0&&j<n-1&&store[j]==search[i]){
					printf("%d %d",store[j-1],store[j+1]);
				}
				else if(j==n-1&&store[j]==search[i]){
					printf("%d",store[j-1]);
				}
					
				if(search[i]==store[j]){
					flag=1;
				}
	
			}
			if(flag==0){
				printf("NULL");
			}
			printf("\n");
		}
	}
}


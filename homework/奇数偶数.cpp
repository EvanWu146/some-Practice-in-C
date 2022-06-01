#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	
	int old[n];
	for(i=0;i<=n-1;i++){
		scanf("%d",&old[i]);
	}
	
	int recent[n];
	for(j=0,i=0;i<=n-1;i++){
		if(old[i]%2==0){
			recent[j]=old[i];
			j++;
		}
	}
	for(i=0;i<=n-1;i++){
		if(old[i]%2!=0){
			recent[j]=old[i];
			j++;
		}
	}
	for(j=0;j<=n-1;j++){
		printf("%d ",recent[j]);
	}
}


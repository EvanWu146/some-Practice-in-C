#include<stdio.h>
int binarySearch(int a[],int searchKey,int low,int high)
{
	int middle;
	middle=low/2+high/2;
	while(low<=high&&a[middle]!=searchKey){
		if(searchKey<a[middle]){
			high=middle-1;
		}
		else low=middle+1;
		middle=(low+high)/2;
	}
	if(low>high) return -1;
	else return middle;
	
}
int main()
{
	long int n,m;
	
	scanf("%ld",&n);
	scanf("%ld",&m);
	int store[n],search[m],i,j;
	for(i=0;i<=n-1;i++){
		scanf("%d",&store[i]);
	}
	for(i=0;i<=m-1;i++){
		scanf("%d",&search[i]);
	}
	for(i=0;i<=m-1;i++){
		printf("%d ",binarySearch(store,search[i],0,n-1));
	}
	printf("\n");
}

	

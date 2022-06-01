#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int *a,int n,int key){
	int low,mid,high;
	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(key==a[mid]) return mid;
		else if(key<a[mid]) high=mid-1;
		else low=mid+1;
	}
	return -1;
}
int main(){
	long int n,m,i;
	int *store,*find;
	store=(int *)malloc(sizeof(int)*2000000);
	find=(int *)malloc(sizeof(int)*100000);
	scanf("%ld",&n);
	scanf("%ld",&m);
	for(i=0;i<=n-1;i++) scanf("%d",&store[i]);
	for(i=0;i<=m-1;i++) scanf("%d",&find[i]);
	for(i=0;i<=m-1;i++){
		printf("%d ",BinarySearch(store,n,find[i]));
	}
	free(store);
	free(find); 
}

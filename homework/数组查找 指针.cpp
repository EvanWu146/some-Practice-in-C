#include<stdio.h>
int findarray(int *array,int element,int size){
	int i,flag=0;
	for(i=0;i<=size-1;i++){
		if(*(array+i)==element) flag=i;
	}
	if(flag) return flag;
	else return -1;
}
int main(){
	int a[1000],find[100],i,n,m,tem;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<=m-1;i++) scanf("%d",&find[i]);
	
	for(i=0;i<=m-1;i++){
		tem=findarray(a,find[i],n);
		if(tem!=-1){
			if(tem>=0&&n==1){
				printf("NULL");
			}
			else if(tem>0&&tem<n-1){
				printf("%d %d",a[tem-1],a[tem+1]);
			}
			else if(tem==0){
				printf("%d",a[tem+1]);
			}
			else if(tem==n-1){
				printf("%d",a[tem-1]);
			}
		}
		else printf("NULL");
		printf("\n");
	}
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,n,i;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
		a[i]=10*a[i]*(-1);
	}
	for(i=0;i<=n-1;i++) printf("%d ",a[i]);
	free(a);
 } 

#include<stdio.h>
void SelectSort(int a[],int n)
{
	int j,temp,mid,k,i;
	for(j=0;j<=n-2;j++){
		for(k=j,mid=k;k<=n-1;k++){
			if(a[k]<a[mid]){
				mid=k;
			}
		}
		temp=a[j];
		a[j]=a[mid];
		a[mid]=temp;
		for(i=0;i<=n-1;i++) printf("%d ",a[i]);
		if(i!=n-2) printf("\n");
		else printf(" "); 
	}
}
int main()
{
	int a[1000],n,i,mid,pass,j;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++) scanf("%d",&a[i]);	
	SelectSort(a,n);
}


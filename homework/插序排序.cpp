#include<stdio.h>
void insert_sort(int a[],int x) {
    int i,j,temp;
    for(j=x-1;j>=1;j--){
    	if(a[x]>=a[j-1]&&a[x]<a[j]){
    		for(i=x;i>=j+1;i--){
    			temp=a[i];
    			a[i]=a[i-1];
    			a[i-1]=temp;
			}
			break;
		}
	}
}
int main()
{
	int a[1001]={0},n,i,mid,pass,j;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(pass=2;pass<=n;pass++){
		insert_sort(a,pass);
		for(i=1;i<=n;i++) printf("%d ",a[i]);
		if(pass!=n) printf("\n");
		else printf(" "); 
	}
	
}


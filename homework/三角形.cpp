#include<stdio.h>
int main()
{
	int n,i,j,k,x=0;
	scanf("%d",&n);
	
	for(i=1;i<n;i++){
		for(j=i;j<n;j++){
			for(k=j;k<n;k++){
				if(i+j+k==n&&i+k>j&&i+j>k&&j+k>i){
					x++;
				}
			}
		}
	}
	printf("%d",x);
}

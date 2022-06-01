#include<stdio.h>
int main()
{
	int i,j,n,a[6][6],h,count=0;
	int d,x,d1,x1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		h=0;
		d=a[i][h];
		x=d;
		for(j=1;j<n;j++){
			if(a[i][h]<a[i][j]){
				d=a[i][j];
			}
			if(a[i][j]==a[i][h])continue;
		}
	}
	for(j=0;j<n;j++){
		if(a[i][h]>a[j][h]){
			break;
		}
	}
	if(j==n){
		printf("The saddle point is (%d,%d)=%d.",i,h,a[i][h]);
		count++;
	}
	if(count==0){
		printf("There is no saddle point in the matrix.");
	}
}

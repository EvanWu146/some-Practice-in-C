#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	a=(int **)malloc(sizeof(int*)*n);
	for(i=0;i<=n-1;i++) a[i]=(int *)malloc(sizeof(int)*m);
	for(i=0;i<=n-1;i++){
		for(j=0;j<=m-1;j++){
			scanf("%d",&a[i][j]);
			a[i][j]=a[i][j]*(-1)*10;
		}
	}
	for(i=0;i<=n-1;i++){
		for(j=0;j<=m-1;j++){
			printf("%d",a[i][j]);
			if(j!=m-1) printf(" ");
			else printf("\n");
		}
	}
	for(i=0;i<=n-1;i++) free(a[i]);
	free(a);
	
}

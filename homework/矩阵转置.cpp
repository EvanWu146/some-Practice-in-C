#include<stdio.h>
int main()
{
	int array[100][100];
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=m-1;j++){
			scanf("%d",&array[i][j]);
		}
	}
	for(j=0;j<=m-1;j++){
		for(i=0;i<=n-1;i++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}

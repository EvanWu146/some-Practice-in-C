#include<stdio.h>
void findMin(int M[][100],int x[],int n,int m){
	int i,j,min;
	for(i=0;i<=m-1;i++){
		min=0;
		for(j=0,min=M[j][i];j<=n-1;j++){
			if(M[j][i]<min){
				min=M[j][i];
			}
		}
		x[i]=min;
	}
}
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	int M[100][100],x[100];
	for(i=0;i<=n-1;i++){
		for(j=0;j<=m-1;j++){
			scanf("%d",&M[i][j]);
		}
	}
	findMin(M,x,n,m);
	for(i=0;i<=m-1;i++) printf("%d ",x[i]);
	printf("\n");
}


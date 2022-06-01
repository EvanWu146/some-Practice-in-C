#include<stdio.h>
int main()
{
	int array[100][100],n,m;
	int i,j;
	int col,row,max,min,row1;
	int x,y,x1,y1;
	int flag=0;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<=n-1;i++){
		for(j=0;j<=m-1;j++){
			scanf("%d",&array[i][j]);
		}
	}
	for(row=0;row<=n-1;row++){
		for(col=0,max=array[row][col];col<=m-1;col++){
			if(max<=array[row][col]){
				x=row;
				y=col;
				max=array[row][col];
			}	
		}
		for(row1=0,min=array[row1][y];row1<=n-1;row1++){
			if(array[row1][y]<=min){
				x1=row1;
				min=array[row1][y];
			}	
		}	
		if(x==x1){
			printf("The saddle point is (%d,%d)=%d.\n",x,y,array[x][y]);
			flag=1;
		}	
	}
	if(flag==0) printf("There is no saddle point in the matrix.\n");
}


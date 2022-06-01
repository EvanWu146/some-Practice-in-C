#include<stdio.h>
int main()
{
	int i,n,col,j,element,snake[100][100]={1};
	int up=1,down=0;
	scanf("%d",&n);
	for(element=2,i=1,j=0;element<=n*n;element++)
	{
		snake[i][j]=element;
		if(down==1){	
			if(j==0||i==n-1){
				up=1;
				down=0;
				if(i<n-1){
					i++;
				}
				else{
					j++;
				}
			}
			else if(j!=0&&i!=n-1){
				i++;
				j--;
			}	
		}
		else if(up==1){
			if(i==0||j==n-1){
				up=0;
				down=1;
				if(j<n-1){
					j++;
				}
				else{
					i++;
				}
			}
			else{
				i--;
				j++;	
			}	
		}
	}
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			printf("%d",snake[i][j]);
			if(j!=n-1) printf(" ");
			else printf("\n");
		}
	}
}

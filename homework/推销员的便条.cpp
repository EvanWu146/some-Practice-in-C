#include<stdio.h>
int main()
{
	int n,i,j;
	int s,p;
	float data[6][5]={0.0},temp,rowtotal,coltotal;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&s,&p);
		scanf("%f",&temp);
		data[p-1][s-1]+=temp;
	}
	for(i=0;i<=4;i++){
		rowtotal=0.000;
		for(j=0;j<=3;j++){
			rowtotal+=data[i][j];
		}
		data[i][4]=rowtotal;
	}
	for(i=0;i<=4;i++){
		coltotal=0.0;
		for(j=0;j<=4;j++){
			coltotal+=data[j][i];
		}
		data[5][i]=coltotal;
	}
	for(i=0;i<=5;i++){
		for(j=0;j<=4;j++){
			printf("%.1f	",data[i][j]);
		}
		printf("\n");
	}
	
}



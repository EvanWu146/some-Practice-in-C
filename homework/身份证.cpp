#include<stdio.h>
int main()
{
	int t,T;
	char idnum[19];
	int M;
	M='X';
	int check[]={1,0,M,9,8,7,6,5,4,3,2};
	int coe[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int i,sum,j;
	int c;
	
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%s",idnum);
		for(j=0,sum=0;j<=16;j++){
			sum=coe[j]*(idnum[j]-'0')+sum;
		}
		sum%=11;
		for(j=0;j<=10;j++){
			if(j==sum){
				c=check[j];
			}
		}
		if(c!=M&&c==idnum[17]-'0') printf("right\n");
		else if(c!=M&&c!=idnum[17]-'0') printf("wrong\n");
		else if(c==M&&c==idnum[17]) printf("right\n");
		else if(c==M&&c!=idnum[17]) printf("wrong\n");
	}
} 

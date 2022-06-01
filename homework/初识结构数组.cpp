#include<stdio.h>
#include<string.h>
struct elements{
	char name[21];
	char id[21];
	int score[5];
};
int main(){
	struct elements stu[100];
	int n,i,j,k,temp,sum;
	scanf("%d",&n);
	
	for(i=0;i<=n-1;i++){
		getchar();
		gets(stu[i].name);
		gets(stu[i].id);
		for(j=0;j<=4;j++){
			scanf("%d",&(stu[i].score[j]));
		}
	}
	
	for(k=0;k<=n-1;k++){
		printf("Name:%s\n",stu[k].name);
		printf("ID:%s\n",stu[k].id);
		printf("Score:");
		for(i=0,sum=0;i<=4;i++){
			printf("%d ",stu[k].score[i]);
			sum+=stu[k].score[i];
		}
		printf("\naverage:%.2f",0.2*sum);
		printf(" total:%d\n",sum);
		printf("\n");
	}
}


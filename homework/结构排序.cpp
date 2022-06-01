#include<stdio.h>
#include<string.h>
struct totalscore{
	char name[21];
	int score;
};
int main(){
	struct totalscore stu[100];
	struct totalscore *ptrstu;
	int n,i,j,temp;
	char tem[21];
	scanf("%d",&n);
	for(i=0;i<=n-1;i++){
		scanf("%s",stu[i].name);
		scanf("%d",&stu[i].score); 
	}
	for(i=1;i<=n-1;i++){
		for(j=0;j<n-i;j++){
			if(stu[j].score<stu[j+1].score){
				temp=stu[j].score;
				stu[j].score=stu[j+1].score;
				stu[j+1].score=temp;
				
				strcpy(tem,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,tem);
			}
			
		}
	}
	for(i=1;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			if(strcmp(stu[j].name,stu[j+1].name)>0&&stu[j].score==stu[j+1].score){
				strcpy(tem,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,tem);
			}
		}	
	}
	
	for(i=0;i<=n-1;i++){
		printf("Name:%s\n",stu[i].name);
		printf("total:%d\n",stu[i].score);
		printf("\n");
	}
}

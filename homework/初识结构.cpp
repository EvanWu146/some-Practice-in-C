#include<stdio.h>
#include<string.h>
struct elements{
	char name[21];
	char ID[21];
	int score[5];
	
}stu;
int main()
{
	struct elements *ptr;
	ptr=&stu;
	int i,j,temp;
	gets(stu.name);
	gets(stu.ID);
	for(i=0;i<=4;i++){
		scanf("%d",&stu.score[i]);
	}
	for(i=1;i<=4;i++){
		for(j=0;j<=4-i;j++){
			if(stu.score[j]<stu.score[j+1]){
				temp=stu.score[j];
				stu.score[j]=stu.score[j+1];
				stu.score[j+1]=temp;
			}
		}
	}
	printf("Name:%s\n",ptr->name);
	printf("ID:%s\n",ptr->ID);
	printf("Score:");
	for(i=0;i<=4;i++){
		printf("%d ",*((ptr->score)+i));
	}
	printf("\naverage:%.2f",0.2*(*(ptr->score)+*(ptr->score+1)+*(ptr->score+2)+*(ptr->score+3)+*(ptr->score+4)));
	printf(" total:%d",*(ptr->score)+*(ptr->score+1)+*(ptr->score+2)+*(ptr->score+3)+*(ptr->score+4));
}

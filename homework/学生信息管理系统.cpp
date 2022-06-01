#include<stdio.h>
#include<string.h>
typedef struct student{
	char name[11];
	char id[11];
	int math;
	int English;
	int cs;
}stu;
void Addstu(stu *student,int *num){
	stu inputstu;
	char temp[11];
	int i,flag=0;
	scanf("%s",inputstu.id);
	scanf("%s",inputstu.name);
	scanf("%d",&inputstu.math);
	scanf("%d",&inputstu.English);
	scanf("%d",&inputstu.cs);
	for(i=0;i<=(*num)-1;i++){
		strcpy(temp,inputstu.id);
		if(strcmp(temp,student[i].id)==0){
			flag=1;
		}
	}
	if(flag==1) printf("Students already exist\n");
	else{
		printf("Add success\n");
		student[i]=inputstu;
		(*num)++;
	}
}
void Deletestu(stu *student,int *num){
	int i,j,flag=0;
	char id[11];
	scanf("%s",id);
	for(i=0;i<=(*num)-1;i++){
		if(strcmp(id,student[i].id)==0){
			for(j=i;j<=(*num)-1;j++){
				student[j]=student[j+1];
			}
			student[j-1]={'\0','\0',0,0,0};
			flag=1;
		}
	}
	if(flag==0) printf("Students do not exist\n");
	else{
		printf("Delete success\n");
		(*num)--;
	}
}
void Updatestu(stu *student,int *num){
	stu inputstu;
	char temp[11];
	int i,flag=0;
	scanf("%s",inputstu.id);
	scanf("%d",&inputstu.math);
	scanf("%d",&inputstu.English);
	scanf("%d",&inputstu.cs);
	for(i=0;i<=(*num)-1;i++){
		strcpy(temp,inputstu.id);
		if(strcmp(temp,student[i].id)==0){
			strcpy(inputstu.name,student[i].name);
			student[i]=inputstu;
			flag=1;
		}
	}
	if(flag==0) printf("Students do not exist\n");
	else printf("Update success\n");
}
void Averagestu(stu *student,int *num){
	int i,flag=0;
	float ave;
	char id[11];
	scanf("%s",id);
	for(i=0;i<=(*num)-1;i++){
		if(strcmp(id,student[i].id)==0){
			ave=(float)(student[i].cs+student[i].English+student[i].math)/3.0;
			flag=1;
			break;
		}
	}
	if(flag==0) printf("Students do not exist\n");
	else printf("Student ID:%s\nName:%s\nAverage Score:%.1f\n",student[i].id,student[i].name,ave);
}
int main(){
	stu STU[131]={'\0','\0',0,0,0};
	int i=0,n,j,size=0,fun;
	scanf("%d",&n);
	while(i<=n-1){
		scanf("%d",&fun);
		if(fun==1) Addstu(STU,&size);
		else if(fun==2) Deletestu(STU,&size);
		else if(fun==3) Updatestu(STU,&size);
		else if(fun==4) Averagestu(STU,&size);
		i++;
	}
}

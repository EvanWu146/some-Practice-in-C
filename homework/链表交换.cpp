#include<stdio.h>
#include<stdlib.h>
typedef struct Listnode{
	int data;
	struct Listnode *nextPTR;
}NODE;
typedef NODE *LNPTR;
//���������� 
LNPTR createNODE(){
	LNPTR currentptr=NULL,lastptr=NULL,headptr=NULL;
	int num;
	headptr=(LNPTR)malloc(sizeof(NODE));
	if(headptr!=NULL){
		headptr->nextPTR=NULL;
		lastptr=headptr;
	}//�������׽�� 
	scanf("%d",&num);
	while(num!=-1){
		currentptr=(LNPTR)malloc(sizeof(NODE));
		if(currentptr!=NULL){
			currentptr->data=num;
			lastptr->nextPTR=currentptr;
			lastptr=currentptr;
		}
		scanf("%d",&num);
	}//�������ݴ������� 
	currentptr=(LNPTR)malloc(sizeof(NODE));
	lastptr->nextPTR=currentptr;
	currentptr->nextPTR=NULL;//������ĩ��� 
	return headptr;
}
//�ҵ�Ŀ�������� 
void findNODE(LNPTR headptr,LNPTR *Sptr,LNPTR *Tptr,int S,int T){
	int pass=0;
	for(pass;pass<=T;pass++){
		if(pass==S-1)	*(Sptr)=headptr;//�ҵ���˵��ǰ����� 
		if(pass==T)		*(Tptr)=headptr;//�ҵ��Ҷ˵��Ӧ�Ľ�� 
		headptr=headptr->nextPTR;
	}
}
//���������ӦƬ��(��������˵㲻�ٽ�)
void swapNODE1(LNPTR Sptr1,LNPTR Tptr1,LNPTR Sptr2,LNPTR Tptr2){
	LNPTR temptr1,temptr2;
	
	temptr1=Sptr1->nextPTR;
	temptr2=Tptr2->nextPTR;//��¼����˵�ǰ���Ҷ˵��������ַ 
	
	Sptr1->nextPTR=Sptr2->nextPTR;
	Tptr2->nextPTR=Tptr1->nextPTR;
	Sptr2->nextPTR=temptr1;
	Tptr1->nextPTR=temptr2;//����Ƭ�� 
}
//���������ӦƬ�Σ���������˵��ٽ���
void swapNODE2 (LNPTR Sptr1,LNPTR Tptr1,LNPTR Sptr2,LNPTR Tptr2){
	LNPTR temptr1,temptr2;
	temptr1=Sptr1->nextPTR;
	temptr2=Tptr2->nextPTR;//��¼���Ҷ˵��������ַ 
	
	Sptr1->nextPTR=Sptr2->nextPTR;
	Tptr2->nextPTR=temptr1;
	Tptr1->nextPTR=temptr2;//����Ƭ�� 
} 
//�ͷ��ڴ溯�� 
void freeNODE(LNPTR headptr){
	LNPTR tempptr=NULL;
	while(headptr!=NULL){
		tempptr=headptr;
		headptr=headptr->nextPTR;
		free(tempptr);
	}
}
//��������� 
void printNODE(LNPTR headptr){
	printf("The new list is:");
	for(headptr=headptr->nextPTR;headptr->nextPTR!=NULL;headptr=headptr->nextPTR){
		printf("%d ",headptr->data);
	}
}
int main(){
	LNPTR Spointer1=NULL,Tpointer1=NULL,Spointer2=NULL,Tpointer2=NULL,headPTR=NULL;
	int s1=0,t1=0,s2=0,t2=0;
	headPTR=createNODE();
	scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
	findNODE(headPTR,&Spointer1,&Tpointer1,s1,t1);
	findNODE(headPTR,&Spointer2,&Tpointer2,s2,t2);
	if(t1+1<s2){
		swapNODE1(Spointer1,Tpointer1,Spointer2,Tpointer2);
	}
	else swapNODE2(Spointer1,Tpointer1,Spointer2,Tpointer2);
	printNODE(headPTR);
	freeNODE(headPTR);
}

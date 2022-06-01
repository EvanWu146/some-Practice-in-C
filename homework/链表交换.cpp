#include<stdio.h>
#include<stdlib.h>
typedef struct Listnode{
	int data;
	struct Listnode *nextPTR;
}NODE;
typedef NODE *LNPTR;
//创建链表函数 
LNPTR createNODE(){
	LNPTR currentptr=NULL,lastptr=NULL,headptr=NULL;
	int num;
	headptr=(LNPTR)malloc(sizeof(NODE));
	if(headptr!=NULL){
		headptr->nextPTR=NULL;
		lastptr=headptr;
	}//创建空首结点 
	scanf("%d",&num);
	while(num!=-1){
		currentptr=(LNPTR)malloc(sizeof(NODE));
		if(currentptr!=NULL){
			currentptr->data=num;
			lastptr->nextPTR=currentptr;
			lastptr=currentptr;
		}
		scanf("%d",&num);
	}//输入数据创建链表 
	currentptr=(LNPTR)malloc(sizeof(NODE));
	lastptr->nextPTR=currentptr;
	currentptr->nextPTR=NULL;//创建空末结点 
	return headptr;
}
//找到目标链表结点 
void findNODE(LNPTR headptr,LNPTR *Sptr,LNPTR *Tptr,int S,int T){
	int pass=0;
	for(pass;pass<=T;pass++){
		if(pass==S-1)	*(Sptr)=headptr;//找到左端点的前驱结点 
		if(pass==T)		*(Tptr)=headptr;//找到右端点对应的结点 
		headptr=headptr->nextPTR;
	}
}
//交换链表对应片段(当两区间端点不临近)
void swapNODE1(LNPTR Sptr1,LNPTR Tptr1,LNPTR Sptr2,LNPTR Tptr2){
	LNPTR temptr1,temptr2;
	
	temptr1=Sptr1->nextPTR;
	temptr2=Tptr2->nextPTR;//记录下左端点前和右端点后的链表地址 
	
	Sptr1->nextPTR=Sptr2->nextPTR;
	Tptr2->nextPTR=Tptr1->nextPTR;
	Sptr2->nextPTR=temptr1;
	Tptr1->nextPTR=temptr2;//交换片段 
}
//交换链表对应片段（当两区间端点临近）
void swapNODE2 (LNPTR Sptr1,LNPTR Tptr1,LNPTR Sptr2,LNPTR Tptr2){
	LNPTR temptr1,temptr2;
	temptr1=Sptr1->nextPTR;
	temptr2=Tptr2->nextPTR;//记录下右端点后的链表地址 
	
	Sptr1->nextPTR=Sptr2->nextPTR;
	Tptr2->nextPTR=temptr1;
	Tptr1->nextPTR=temptr2;//交换片段 
} 
//释放内存函数 
void freeNODE(LNPTR headptr){
	LNPTR tempptr=NULL;
	while(headptr!=NULL){
		tempptr=headptr;
		headptr=headptr->nextPTR;
		free(tempptr);
	}
}
//输出链表函数 
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

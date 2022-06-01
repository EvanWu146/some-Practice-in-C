#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *nextPTR;
}NODE; 
typedef NODE *NODEPTR;
/*````````````````````````````````````````````````````````
函数名称：createlistnode
功能：创建首结点为空结点的链表 
````````````````````````````````````````````````````````*/ 
NODEPTR createNODE(){
	NODEPTR	headptr,currentptr,lastptr;
	int num;
	headptr=(NODEPTR)malloc(sizeof(NODE));
	if(headptr!=NULL){
		headptr->nextPTR=NULL;
		lastptr=headptr;
	}//创建空首结点 
	scanf("%d",&num);
	while(num!=-1){
		currentptr=(NODEPTR)malloc(sizeof(NODE));
		if(currentptr!=NULL){
			currentptr->data=num;
			lastptr->nextPTR=currentptr;
			lastptr=currentptr;//插入数据，连接上一节点，并修正lastptr 
		}
		scanf("%d",&num);
	}
	lastptr->nextPTR=NULL; 
	return headptr;
} 
//比较链表函数 
int compareNODE(NODEPTR P1,NODEPTR P2){
	int flag=0;
	for(;P1!=NULL&&P2!=NULL&&flag==0;P1=P1->nextPTR,P2=P2->nextPTR){//循环条件：指针不为空，flag未改变 
		if(P1->data!=P2->data) flag=1;
	};
	if(flag==0){
		if(P1==NULL&&P2!=NULL) return 0;
		else return 1;
	} 
	else return 0;
}
/*-------------------------------------------------
函数名称：findsamenumNODE
作用：找到链表A中与链表B首数据相同的数据 
-------------------------------------------------*/ 
int findsamenumNODE(NODEPTR headptr1,NODEPTR headptr2){
	NODEPTR  p1=headptr1->nextPTR,p2=headptr2->nextPTR;
	int flag=0,num2=p2->data;
	for(;p1!=NULL&&flag==0;p1=p1->nextPTR){
		if(p1->data==num2){//找到相同的数据就进行比较链表 
			if(compareNODE(p1,p2)==1){
				flag=1;
				return 1;
			}
		}
	}
	if(flag==0) return 0;
}

//释放内存函数 
freeNODE(NODEPTR headptr){
	NODEPTR tempptr;
	while(headptr!=NULL){
		tempptr=headptr;
		headptr=headptr->nextPTR;
		free(tempptr);
	}
}
int main(){
	NODEPTR headPTR1,headPTR2;
	headPTR1=createNODE();
	headPTR2=createNODE();
	if(findsamenumNODE(headPTR1,headPTR2)==1){
		printf("ListB is the sub sequence of ListA.");
	}
	else printf("ListB is not the sub sequence of ListA.");
	freeNODE(headPTR1);
	freeNODE(headPTR2);
}

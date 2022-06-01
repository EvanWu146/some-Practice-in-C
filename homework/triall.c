#include<stdio.h>
#include<stdlib.h>
typedef struct listnode{
	int data;
	struct listnode *NEXTPTR;
}NODE; 
typedef NODE *LNPTR;
//createNODE函数：创建链表 
LNPTR createNODE(){
	LNPTR currentPTR=NULL,lastPTR=NULL,headPTR=NULL;
	int num;
	headPTR=malloc(sizeof(NODE));
	if(headPTR!=NULL){
		headPTR->NEXTPTR=NULL;
		lastPTR=headPTR;
	}//创建空首结点 
	scanf("%d",&num);
	while(num!=-1){
		currentPTR=malloc(sizeof(NODE));
		if(currentPTR!=NULL){
			currentPTR->data=num;
			lastPTR->NEXTPTR=currentPTR;
			lastPTR=currentPTR;
		}
		scanf("%d",&num);
	}//创建链表中间部分 
	lastPTR->NEXTPTR=NULL;//将末指针设为null 
	return headPTR;
}
//printNODE函数：输出链表 
void printNODE(LNPTR headPtr,char serial){
	if(headPtr->NEXTPTR->NEXTPTR=NULL){
		printf("There is no item in %c list.",serial);
	}//链表中没有数据 
	else{
		printf("The new list %c:",serial);
		for(headPtr=headPtr->NEXTPTR;headPtr->NEXTPTR!=NULL;headPtr=headPtr->NEXTPTR){
			printf("%d ",headPtr->data);
	}
	} 
}
//destroyNODE函数：释放链表内存 
void destroyNODE(LNPTR headPtr){
	LNPTR temPtr;
	while(headPtr!=NULL){
		temPtr=headPtr;
		headPtr=headPtr->NEXTPTR;
		free(temPtr);
	}
}
main(){
	LNPTR headptr;
	headptr=createNODE();
	printNODE(headptr,'a');
	destroyNODE(headptr);
}

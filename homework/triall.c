#include<stdio.h>
#include<stdlib.h>
typedef struct listnode{
	int data;
	struct listnode *NEXTPTR;
}NODE; 
typedef NODE *LNPTR;
//createNODE�������������� 
LNPTR createNODE(){
	LNPTR currentPTR=NULL,lastPTR=NULL,headPTR=NULL;
	int num;
	headPTR=malloc(sizeof(NODE));
	if(headPTR!=NULL){
		headPTR->NEXTPTR=NULL;
		lastPTR=headPTR;
	}//�������׽�� 
	scanf("%d",&num);
	while(num!=-1){
		currentPTR=malloc(sizeof(NODE));
		if(currentPTR!=NULL){
			currentPTR->data=num;
			lastPTR->NEXTPTR=currentPTR;
			lastPTR=currentPTR;
		}
		scanf("%d",&num);
	}//���������м䲿�� 
	lastPTR->NEXTPTR=NULL;//��ĩָ����Ϊnull 
	return headPTR;
}
//printNODE������������� 
void printNODE(LNPTR headPtr,char serial){
	if(headPtr->NEXTPTR->NEXTPTR=NULL){
		printf("There is no item in %c list.",serial);
	}//������û������ 
	else{
		printf("The new list %c:",serial);
		for(headPtr=headPtr->NEXTPTR;headPtr->NEXTPTR!=NULL;headPtr=headPtr->NEXTPTR){
			printf("%d ",headPtr->data);
	}
	} 
}
//destroyNODE�������ͷ������ڴ� 
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

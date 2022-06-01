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
	currentPTR=malloc(sizeof(NODE));
	if(currentPTR!=NULL){
		currentPTR->NEXTPTR=NULL;
		lastPTR->NEXTPTR=currentPTR;
	}//创建空末结点 ，辅助功能 

	return headPTR;
}
//printNODE函数：输出链表 
void printNODE(LNPTR headPtr,char serial){
	if(headPtr->NEXTPTR->NEXTPTR==NULL){
		printf("There is no item in %c list.",serial);
	}//链表中没有数据 
	else{
		printf("The new list %c:",serial);
		headPtr=headPtr->NEXTPTR;
		while(headPtr->NEXTPTR!=NULL){
			printf("%d ",headPtr->data);
			headPtr=headPtr->NEXTPTR;
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
//insertNODE函数：插入结点
void insertNODE(LNPTR hPTR2,LNPTR beinsertedPTR){
	LNPTR temPTR1,temPTR2;
	if(beinsertedPTR->NEXTPTR->NEXTPTR!=NULL)
	{
		temPTR1=beinsertedPTR->NEXTPTR;
		temPTR2=hPTR2->NEXTPTR->NEXTPTR;
		beinsertedPTR->NEXTPTR=hPTR2->NEXTPTR;
		hPTR2->NEXTPTR=temPTR2;
		beinsertedPTR->NEXTPTR->NEXTPTR=temPTR1;
	} //将链表插入中间部分 
	else{
		temPTR2=beinsertedPTR->NEXTPTR;
		beinsertedPTR->NEXTPTR=hPTR2->NEXTPTR;
		hPTR2->NEXTPTR=temPTR2;	
	}//将链表插入A中最后一个元素的后面 	
}
//findTargetNODE函数：寻找需要插入结点的位置
void findTargetNODE(LNPTR headPtr1,LNPTR headPtr2){
	LNPTR temPTR=headPtr1;
	int flag=0;
	if(headPtr2->NEXTPTR==NULL){
		return;
	}
	else{
		while(temPTR->NEXTPTR!=NULL&&headPtr2->NEXTPTR->NEXTPTR!=NULL){
			if(((temPTR->NEXTPTR->data)>(headPtr2->NEXTPTR->data))
				||((temPTR->NEXTPTR->NEXTPTR==NULL)&&(temPTR->data<headPtr2->NEXTPTR->data))){
				insertNODE(headPtr2,temPTR);//情况1：A中指向数据小于B中指向数据，将B中数据插入A指向数据之后 
				
				temPTR=temPTR->NEXTPTR;
			}
			else if((temPTR->NEXTPTR->data)==(headPtr2->NEXTPTR->data)
					||((temPTR->NEXTPTR->NEXTPTR==NULL)&&(temPTR->data==headPtr2->NEXTPTR->data))){
				headPtr2=headPtr2->NEXTPTR;//情况2：元素相等，B中指针跳过该元素向后移，
				
			}
			else if((temPTR->NEXTPTR->data)<(headPtr2->NEXTPTR->data)){
				temPTR=temPTR->NEXTPTR;//情况3： 不符合插入条件，A中指针向后移 
			}
		}
	}
} 
int main(){
	LNPTR headPTRA,headPTRB;
	headPTRA=createNODE();
	headPTRB=createNODE();
	findTargetNODE(headPTRA,headPTRB);
	printNODE(headPTRA,'A');
	printf("\n");
	printNODE(headPTRB,'B');

	destroyNODE(headPTRA);
	destroyNODE(headPTRB); 
}

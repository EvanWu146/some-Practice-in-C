#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *nextPTR;
}NODE; 
typedef NODE *NODEPTR;
/*````````````````````````````````````````````````````````
�������ƣ�createlistnode
���ܣ������׽��Ϊ�ս������� 
````````````````````````````````````````````````````````*/ 
NODEPTR createNODE(){
	NODEPTR	headptr,currentptr,lastptr;
	int num;
	headptr=(NODEPTR)malloc(sizeof(NODE));
	if(headptr!=NULL){
		headptr->nextPTR=NULL;
		lastptr=headptr;
	}//�������׽�� 
	scanf("%d",&num);
	while(num!=-1){
		currentptr=(NODEPTR)malloc(sizeof(NODE));
		if(currentptr!=NULL){
			currentptr->data=num;
			lastptr->nextPTR=currentptr;
			lastptr=currentptr;//�������ݣ�������һ�ڵ㣬������lastptr 
		}
		scanf("%d",&num);
	}
	lastptr->nextPTR=NULL; 
	return headptr;
} 
//�Ƚ������� 
int compareNODE(NODEPTR P1,NODEPTR P2){
	int flag=0;
	for(;P1!=NULL&&P2!=NULL&&flag==0;P1=P1->nextPTR,P2=P2->nextPTR){//ѭ��������ָ�벻Ϊ�գ�flagδ�ı� 
		if(P1->data!=P2->data) flag=1;
	};
	if(flag==0){
		if(P1==NULL&&P2!=NULL) return 0;
		else return 1;
	} 
	else return 0;
}
/*-------------------------------------------------
�������ƣ�findsamenumNODE
���ã��ҵ�����A��������B��������ͬ������ 
-------------------------------------------------*/ 
int findsamenumNODE(NODEPTR headptr1,NODEPTR headptr2){
	NODEPTR  p1=headptr1->nextPTR,p2=headptr2->nextPTR;
	int flag=0,num2=p2->data;
	for(;p1!=NULL&&flag==0;p1=p1->nextPTR){
		if(p1->data==num2){//�ҵ���ͬ�����ݾͽ��бȽ����� 
			if(compareNODE(p1,p2)==1){
				flag=1;
				return 1;
			}
		}
	}
	if(flag==0) return 0;
}

//�ͷ��ڴ溯�� 
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

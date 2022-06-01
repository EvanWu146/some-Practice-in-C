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
	currentPTR=malloc(sizeof(NODE));
	if(currentPTR!=NULL){
		currentPTR->NEXTPTR=NULL;
		lastPTR->NEXTPTR=currentPTR;
	}//������ĩ��� ���������� 

	return headPTR;
}
//printNODE������������� 
void printNODE(LNPTR headPtr,char serial){
	if(headPtr->NEXTPTR->NEXTPTR==NULL){
		printf("There is no item in %c list.",serial);
	}//������û������ 
	else{
		printf("The new list %c:",serial);
		headPtr=headPtr->NEXTPTR;
		while(headPtr->NEXTPTR!=NULL){
			printf("%d ",headPtr->data);
			headPtr=headPtr->NEXTPTR;
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
//insertNODE������������
void insertNODE(LNPTR hPTR2,LNPTR beinsertedPTR){
	LNPTR temPTR1,temPTR2;
	if(beinsertedPTR->NEXTPTR->NEXTPTR!=NULL)
	{
		temPTR1=beinsertedPTR->NEXTPTR;
		temPTR2=hPTR2->NEXTPTR->NEXTPTR;
		beinsertedPTR->NEXTPTR=hPTR2->NEXTPTR;
		hPTR2->NEXTPTR=temPTR2;
		beinsertedPTR->NEXTPTR->NEXTPTR=temPTR1;
	} //����������м䲿�� 
	else{
		temPTR2=beinsertedPTR->NEXTPTR;
		beinsertedPTR->NEXTPTR=hPTR2->NEXTPTR;
		hPTR2->NEXTPTR=temPTR2;	
	}//���������A�����һ��Ԫ�صĺ��� 	
}
//findTargetNODE������Ѱ����Ҫ�������λ��
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
				insertNODE(headPtr2,temPTR);//���1��A��ָ������С��B��ָ�����ݣ���B�����ݲ���Aָ������֮�� 
				
				temPTR=temPTR->NEXTPTR;
			}
			else if((temPTR->NEXTPTR->data)==(headPtr2->NEXTPTR->data)
					||((temPTR->NEXTPTR->NEXTPTR==NULL)&&(temPTR->data==headPtr2->NEXTPTR->data))){
				headPtr2=headPtr2->NEXTPTR;//���2��Ԫ����ȣ�B��ָ��������Ԫ������ƣ�
				
			}
			else if((temPTR->NEXTPTR->data)<(headPtr2->NEXTPTR->data)){
				temPTR=temPTR->NEXTPTR;//���3�� �����ϲ���������A��ָ������� 
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

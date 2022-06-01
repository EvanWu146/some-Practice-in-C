#include<stdio.h>
#include<stdlib.h>
 struct listnode{
	int data;
	struct listnode *nextPtr;
};//����������ṹ�� 
typedef struct listnode LISTNODE;
typedef LISTNODE *LNPTR;//���������ṹ���ͱ�����ָ�����
/*````````````````````````````````````````````````````````
�������ƣ�createlistnode
���ܣ������׽��Ϊ�ս������� 
````````````````````````````````````````````````````````*/ 
LNPTR createListNode(){
	LNPTR currentptr=NULL,lastptr=NULL,headptr=NULL;
	int num;
	headptr=(LNPTR)malloc(sizeof(LISTNODE));
	currentptr=(LNPTR)malloc(sizeof(LISTNODE));
	if(headptr!=NULL&&currentptr!=NULL){
		headptr->nextPtr=currentptr;
		lastptr=currentptr;
	}//�������洢���ݵ��׽�� 
	
	scanf("%d",&num);
	while(num!=-1){
		currentptr=(LNPTR)malloc(sizeof(LISTNODE));
		if(currentptr!=NULL){
			currentptr->data=num;
			lastptr->nextPtr=currentptr;
			lastptr=currentptr;
			scanf("%d",&num);
		}
	}//������������ 
	lastptr->nextPtr=NULL;//��ĩ����nextptr��Ϊ��ָ�� 
	return headptr;
}
/*````````````````````````````````````````````````````````
�������ƣ�sortlistnode
���ܣ�Ϊ����������� 
````````````````````````````````````````````````````````*/ 
void sortlistnode(LNPTR headptr){
	LNPTR p1,p2,p3,end,temp;
	end=NULL;
	if(headptr->nextPtr==NULL)	return;
	if(headptr->nextPtr->nextPtr==NULL)	return;//��û�����ݻ�ֻ��һ���������������� 
	else{
		while(headptr->nextPtr!=end){
			for(p1=headptr,p2=p1->nextPtr,p3=p2->nextPtr;
			    p3!=end;
				p1=p1->nextPtr,p2=p2->nextPtr,p3=p3->nextPtr)//����������ָ������ 
				{		
					if(p2->data>p3->data){//�����������бȽ� 
					p1->nextPtr=p2->nextPtr;
					p2->nextPtr=p3->nextPtr;
					p3->nextPtr=p2;//������� 
					temp=p2;			 
					p2=p3;
					p3=temp;//����p2p3 
					}
			}
			end=p2;//���м���p2Ϊ�ο�����p2=NULL���ѵ�����ĩβ 
		}
	}
	
}
/*````````````````````````````````````````````````````````
�������ƣ�freeeptr
���ܣ��ͷ��ڴ� 
````````````````````````````````````````````````````````*/ 
void freePtr(LNPTR HEADPTR){
	LNPTR TEMPPTR;//��������ָ�� 
	while(HEADPTR!=NULL){
		TEMPPTR=HEADPTR;
		HEADPTR=HEADPTR->nextPtr;//��ָ�������λ 
		free(TEMPPTR);	
	}
}
/*````````````````````````````````````````````````````````
�������ƣ�printlistnode
���ܣ�������� 
````````````````````````````````````````````````````````*/ 
void printlistnode(LNPTR headptr){
	printf("The new list is:");
	headptr=headptr->nextPtr;
	while(headptr!=NULL){
		printf("%d ",headptr->data);
		headptr=headptr->nextPtr;
	}
}
/*������*/ 
main(){
	LNPTR headpointer;
	headpointer=createListNode();
	sortlistnode(headpointer);
	printlistnode(headpointer);
	freePtr(headpointer);
} 

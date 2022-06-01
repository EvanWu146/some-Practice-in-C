#include<stdio.h>
#include<stdlib.h>
 struct listnode{
	int data;
	struct listnode *nextPtr;
};//创建链表结点结构体 
typedef struct listnode LISTNODE;
typedef LISTNODE *LNPTR;//定义该链表结构体型变量及指针变量
/*````````````````````````````````````````````````````````
函数名称：createlistnode
功能：创建首结点为空结点的链表 
````````````````````````````````````````````````````````*/ 
LNPTR createListNode(){
	LNPTR currentptr=NULL,lastptr=NULL,headptr=NULL;
	int num;
	headptr=(LNPTR)malloc(sizeof(LISTNODE));
	currentptr=(LNPTR)malloc(sizeof(LISTNODE));
	if(headptr!=NULL&&currentptr!=NULL){
		headptr->nextPtr=currentptr;
		lastptr=currentptr;
	}//创建不存储数据的首结点 
	
	scanf("%d",&num);
	while(num!=-1){
		currentptr=(LNPTR)malloc(sizeof(LISTNODE));
		if(currentptr!=NULL){
			currentptr->data=num;
			lastptr->nextPtr=currentptr;
			lastptr=currentptr;
			scanf("%d",&num);
		}
	}//创建后续链表 
	lastptr->nextPtr=NULL;//将末结点的nextptr设为空指针 
	return headptr;
}
/*````````````````````````````````````````````````````````
函数名称：sortlistnode
功能：为链表进行排序 
````````````````````````````````````````````````````````*/ 
void sortlistnode(LNPTR headptr){
	LNPTR p1,p2,p3,end,temp;
	end=NULL;
	if(headptr->nextPtr==NULL)	return;
	if(headptr->nextPtr->nextPtr==NULL)	return;//若没有数据或只有一个数据则无需排序 
	else{
		while(headptr->nextPtr!=end){
			for(p1=headptr,p2=p1->nextPtr,p3=p2->nextPtr;
			    p3!=end;
				p1=p1->nextPtr,p2=p2->nextPtr,p3=p3->nextPtr)//用三个连续指针排序 
				{		
					if(p2->data>p3->data){//后两个结点进行比较 
					p1->nextPtr=p2->nextPtr;
					p2->nextPtr=p3->nextPtr;
					p3->nextPtr=p2;//交换结点 
					temp=p2;			 
					p2=p3;
					p3=temp;//修正p2p3 
					}
			}
			end=p2;//以中间结点p2为参考，若p2=NULL则已到链表末尾 
		}
	}
	
}
/*````````````````````````````````````````````````````````
函数名称：freeeptr
功能：释放内存 
````````````````````````````````````````````````````````*/ 
void freePtr(LNPTR HEADPTR){
	LNPTR TEMPPTR;//创建过度指针 
	while(HEADPTR!=NULL){
		TEMPPTR=HEADPTR;
		HEADPTR=HEADPTR->nextPtr;//首指针向后移位 
		free(TEMPPTR);	
	}
}
/*````````````````````````````````````````````````````````
函数名称：printlistnode
功能：输出链表 
````````````````````````````````````````````````````````*/ 
void printlistnode(LNPTR headptr){
	printf("The new list is:");
	headptr=headptr->nextPtr;
	while(headptr!=NULL){
		printf("%d ",headptr->data);
		headptr=headptr->nextPtr;
	}
}
/*主函数*/ 
main(){
	LNPTR headpointer;
	headpointer=createListNode();
	sortlistnode(headpointer);
	printlistnode(headpointer);
	freePtr(headpointer);
} 

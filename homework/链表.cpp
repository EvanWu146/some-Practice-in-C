#include<stdio.h>
#include<stdlib.h>
struct listNode{
	int data;
	struct listNode *nextPtr;
}; 
typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;
LISTNODEPTR createFIFOList1()
{	
	int	num;
 	LISTNODEPTR	headPtr = NULL, lastPtr = NULL, currentPtr = NULL ;
	
	printf("input positive numbers,-1 to end\n");
 	scanf("%d",&num);	
 	while(num!=-1)
	{
	    currentPtr=(LISTNODEPTR)malloc(sizeof(LISTNODE)); /*�������ڴ�*/ 
 	    if (currentPtr!=NULL)
		{/*������*/
 	        currentPtr->data=num;	
    		if (headPtr==NULL)
			{   /*������������Ԫ���*/
    		    headPtr=currentPtr;
                lastPtr=currentPtr; 
            } 	   
          	else
			{
          	    lastPtr->nextPtr=currentPtr;  /*�������������β���*/
              	lastPtr=currentPtr;   /*ʹlastPtrָ��ǰ��������һ�����*/
            }
        }
        scanf("%d",&num);
 	}   
	lastPtr->nextPtr=NULL;/*��������������*/
 	return headPtr; 
}

void printflist(LISTNODEPTR currentPtr){
	if(currentPtr==NULL){
		printf("the list is empty.");
	}
	else{
		printf("the list is:\n");
		while(currentPtr!=NULL){
			printf("%d-->",currentPtr->data);
			currentPtr=currentPtr->nextPtr;
		}
		printf("NULL\n") ;
	}
}
main(){
	LISTNODEPTR headptr=NULL;
	headptr=createFIFOList1();
	printflist(headptr);
}

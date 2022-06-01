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
	    currentPtr=(LISTNODEPTR)malloc(sizeof(LISTNODE)); /*分配结点内存*/ 
 	    if (currentPtr!=NULL)
		{/*插入结点*/
 	        currentPtr->data=num;	
    		if (headPtr==NULL)
			{   /*若创建的是首元结点*/
    		    headPtr=currentPtr;
                lastPtr=currentPtr; 
            } 	   
          	else
			{
          	    lastPtr->nextPtr=currentPtr;  /*将结点连上链表尾结点*/
              	lastPtr=currentPtr;   /*使lastPtr指向当前链表的最后一个结点*/
            }
        }
        scanf("%d",&num);
 	}   
	lastPtr->nextPtr=NULL;/*设置链表结束标记*/
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

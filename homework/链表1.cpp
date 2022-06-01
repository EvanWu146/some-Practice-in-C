#include<stdio.h>
#include<stdlib.h>
struct listnode{
	int data;
	struct listnode *nextPtr;
};//创建链表结点结构体 
typedef struct listnode LISTNODE;
typedef LISTNODE *LNPTR;//定义该链表结构体型变量及指针变量
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
—————————————————————————————
函数名称： createLILOLIST
功能：创建链表，同时计算出最大最小值以及总和，减少遍历链表
次数。 
————————————————————————————— 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

LNPTR createLILOLIST(int *maxPtr,int *minPtr,int *sumPtr){//传入三个值的指针 
	LNPTR currentPtr=NULL,lastPtr=NULL,headPtr=NULL;
	int num;
	scanf("%d",&num); 
	*maxPtr=num;
	*minPtr=num;//将第一个数值复制给最大、最小值；
	
	while(num!=-1){
		currentPtr=(LNPTR)malloc(sizeof(LISTNODE)) ;//为结点创建内存 

		if(currentPtr!=NULL){//若申请成功 
			currentPtr->data=num;// 将数值导入结点 
			if(headPtr==NULL)	headPtr=currentPtr;//若创建的是结点
			else	lastPtr->nextPtr=currentPtr;//不是首结点，则将现结点指针插入上一结点 
				
			lastPtr=currentPtr;//修正lastPtr 
		}
		
		if(num>*maxPtr) *maxPtr=num;
		else if(num<*minPtr) *minPtr=num;//比较大小，更新最大最小值 
		
		*sumPtr=*sumPtr+num;//计算总和 
		scanf("%d",&num);
	}
	lastPtr->nextPtr=NULL;//将末结点的nextptr设为空指针 
	return headPtr;//返回首结点指针 
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
—————————————————————————————
函数名称： freePtr
功能：摧毁链表，释放指针内存 
————————————————————————————— 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void freePtr(LNPTR HEADPTR){
	LNPTR TEMPPTR;//创建过度指针 
	while(HEADPTR!=NULL){
		TEMPPTR=HEADPTR;
		HEADPTR=HEADPTR->nextPtr;//首指针向后移位 
		free(TEMPPTR);	
	}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
—————————————————————————————
主			函			数 
————————————————————————————— 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main(){
	int *maxptr,*minptr,*sumptr;
	LNPTR headpointer;
	maxptr=(int *)malloc(sizeof(int));
	minptr=(int *)malloc(sizeof(int));
	sumptr=(int *)malloc(sizeof(int));//为三个值对应的指针创建内存 
	*sumptr=0;//初始化sum 
	headpointer=createLILOLIST(maxptr,minptr,sumptr);
	printf("The maximum,minmum and the total are:%d %d %d",*maxptr,*minptr,*sumptr);
	freePtr(headpointer);
	free(maxptr);
	free(minptr);
	free(sumptr);//释放内存 
}

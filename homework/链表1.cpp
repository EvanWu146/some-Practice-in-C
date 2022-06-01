#include<stdio.h>
#include<stdlib.h>
struct listnode{
	int data;
	struct listnode *nextPtr;
};//����������ṹ�� 
typedef struct listnode LISTNODE;
typedef LISTNODE *LNPTR;//���������ṹ���ͱ�����ָ�����
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
����������������������������������������������������������
�������ƣ� createLILOLIST
���ܣ���������ͬʱ����������Сֵ�Լ��ܺͣ����ٱ�������
������ 
���������������������������������������������������������� 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

LNPTR createLILOLIST(int *maxPtr,int *minPtr,int *sumPtr){//��������ֵ��ָ�� 
	LNPTR currentPtr=NULL,lastPtr=NULL,headPtr=NULL;
	int num;
	scanf("%d",&num); 
	*maxPtr=num;
	*minPtr=num;//����һ����ֵ���Ƹ������Сֵ��
	
	while(num!=-1){
		currentPtr=(LNPTR)malloc(sizeof(LISTNODE)) ;//Ϊ��㴴���ڴ� 

		if(currentPtr!=NULL){//������ɹ� 
			currentPtr->data=num;// ����ֵ������ 
			if(headPtr==NULL)	headPtr=currentPtr;//���������ǽ��
			else	lastPtr->nextPtr=currentPtr;//�����׽�㣬���ֽ��ָ�������һ��� 
				
			lastPtr=currentPtr;//����lastPtr 
		}
		
		if(num>*maxPtr) *maxPtr=num;
		else if(num<*minPtr) *minPtr=num;//�Ƚϴ�С�����������Сֵ 
		
		*sumPtr=*sumPtr+num;//�����ܺ� 
		scanf("%d",&num);
	}
	lastPtr->nextPtr=NULL;//��ĩ����nextptr��Ϊ��ָ�� 
	return headPtr;//�����׽��ָ�� 
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
����������������������������������������������������������
�������ƣ� freePtr
���ܣ��ݻ������ͷ�ָ���ڴ� 
���������������������������������������������������������� 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void freePtr(LNPTR HEADPTR){
	LNPTR TEMPPTR;//��������ָ�� 
	while(HEADPTR!=NULL){
		TEMPPTR=HEADPTR;
		HEADPTR=HEADPTR->nextPtr;//��ָ�������λ 
		free(TEMPPTR);	
	}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
����������������������������������������������������������
��			��			�� 
���������������������������������������������������������� 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main(){
	int *maxptr,*minptr,*sumptr;
	LNPTR headpointer;
	maxptr=(int *)malloc(sizeof(int));
	minptr=(int *)malloc(sizeof(int));
	sumptr=(int *)malloc(sizeof(int));//Ϊ����ֵ��Ӧ��ָ�봴���ڴ� 
	*sumptr=0;//��ʼ��sum 
	headpointer=createLILOLIST(maxptr,minptr,sumptr);
	printf("The maximum,minmum and the total are:%d %d %d",*maxptr,*minptr,*sumptr);
	freePtr(headpointer);
	free(maxptr);
	free(minptr);
	free(sumptr);//�ͷ��ڴ� 
}

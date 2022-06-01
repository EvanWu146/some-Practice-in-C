#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct listnode{
    char data[3];
    struct listnode *nextPtr;
}NODE; 
typedef NODE *NODEPTR;
//函数：创建主链表 
NODEPTR createNODE(){
    NODEPTR currentPTR=NULL,headPTR=NULL,lastPTR=NULL;
    char DATA[3],end[3]={'-','1'};//end作用：判断输入结束标识符 
    headPTR=(NODEPTR)malloc(sizeof(NODE));
    if(headPTR!=NULL){
        headPTR->nextPtr=NULL;
        lastPTR=headPTR;
    }//设立空表头 
    scanf("%s",DATA);
    while(strcmp(DATA,end)!=0){
        currentPTR=(NODEPTR)malloc(sizeof(NODE));
        if(currentPTR!=NULL){
            strcpy(currentPTR->data,DATA); 
            lastPTR->nextPtr=currentPTR;
            lastPTR=currentPTR;
        }
        scanf("%s",DATA);
    }
    lastPTR->nextPtr=NULL;
    return headPTR;
    
}
//函数：创建空链表
NODEPTR create_EmptyNODE(){
    NODEPTR headPTR=NULL;
    headPTR=(NODEPTR)malloc(sizeof(NODE));
    if(headPTR!=NULL){
        headPTR->nextPtr=NULL;
        return headPTR;
    }
    else return NULL;
} 
//函数：为链表进行排序
void sortNODE(NODEPTR headptr){
    NODEPTR p1,p2,p3,end,tem_PTR;
    end=NULL;
    if(headptr->nextPtr==NULL)    return;
    else if(headptr->nextPtr->nextPtr==NULL)    return;//若没有数据或只有一个数据则无需排序 
    else{
        while(headptr->nextPtr!=end){
            for(p1=headptr,p2=p1->nextPtr,p3=p2->nextPtr;
                p3!=end;
                p1=p1->nextPtr,p2=p2->nextPtr,p3=p3->nextPtr)//用三个连续指针排序 
                {        
                    if(p2->data[0]>p3->data[0]){//后两个结点进行比较 
                        p1->nextPtr=p2->nextPtr;
                        p2->nextPtr=p3->nextPtr;
                        p3->nextPtr=p2;//交换结点 
                        tem_PTR=p2;             
                        p2=p3;
                        p3=tem_PTR;//修正p2p3 
                    }
            }
            end=p2;//以中间结点p2为参考，若p2=NULL则已到链表末尾 
        }
        
    }
}
//函数：输出链表
void printNODE(NODEPTR headPtr,char id){
    
    if(headPtr->nextPtr==NULL) printf("There is no item in %c list.",id);
    else{
        headPtr=headPtr->nextPtr;
        printf("The list %c is:",id);
        while(headPtr!=NULL){
            printf(" %c",headPtr->data[0]);
            headPtr=headPtr->nextPtr;
        }
    }
    printf("\n");
} 
//函数： 释放链表内存
void freeNODE(NODEPTR headPTR){
    NODEPTR tem_PTR;
    while(headPTR!=NULL){
        tem_PTR=headPTR;
        headPTR=headPTR->nextPtr;
        free(tem_PTR);
    }
} 
//insertNODE函数：插入结点
void insertNODE(NODEPTR h_PTR,NODEPTR beinsertedPTR){
    NODEPTR tem_1PTR=h_PTR->nextPtr->nextPtr;//存下后续结点
    
    beinsertedPTR->nextPtr=h_PTR->nextPtr;
    beinsertedPTR->nextPtr->nextPtr=NULL;
    h_PTR->nextPtr=tem_1PTR;
    
}
//函数：将链表数据分类
void classifyNODE(NODEPTR headPTR,NODEPTR A_headPTR,NODEPTR B_headPTR,NODEPTR C_headPTR){
    int num;
    if(headPTR->nextPtr==NULL) return;
    else{

        while(headPTR->nextPtr!=NULL){
            num=(headPTR->nextPtr->data)[0];
            if(num>=48&&num<=57){
                insertNODE(headPTR,B_headPTR);
                B_headPTR=B_headPTR->nextPtr;
            }//数字 
            else if((num>=65&&num<=90)||(num>=97&&num<=122)){
                insertNODE(headPTR,A_headPTR);
                A_headPTR=A_headPTR->nextPtr;
            }//字母 
            else{
                insertNODE(headPTR,C_headPTR);
                C_headPTR=C_headPTR->nextPtr;
            }//其他字符         
        }
    }
}
int main(){
    NODEPTR headPTR=NULL,headPTR_A=NULL,headPTR_B=NULL,headPTR_C=NULL;
    
    headPTR=createNODE();
    headPTR_A=create_EmptyNODE();
    headPTR_B=create_EmptyNODE();
    headPTR_C=create_EmptyNODE();
    
    classifyNODE(headPTR,headPTR_A,headPTR_B,headPTR_C);
    sortNODE(headPTR_A);
    sortNODE(headPTR_B);
    sortNODE(headPTR_C);
    
    printNODE(headPTR_A,'A');
    printNODE(headPTR_B,'B');
    printNODE(headPTR_C,'C');
    
    freeNODE(headPTR_A);
    freeNODE(headPTR_B);
    freeNODE(headPTR_C);
}

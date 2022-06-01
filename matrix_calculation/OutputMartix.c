#include<stdio.h>
#include"headfiles.h"
#include<stdlib.h>
#define TABLE_ELEMENT_SIZE 5
#define TABLE_INCREMENT 5
void ArrayToTable(int **twoDimArr,Table *cPtr)  //将用二维数组存储的矩阵用三元组表存储起来
{
	int i,j,len;
	cPtr->dataPtr = malloc(sizeof(Element)*TABLE_ELEMENT_SIZE);
	if(cPtr->dataPtr!=NULL)
	{
		for(i=1,len=0;i<=cPtr->m;i++)
		{
			for(j=1;j<=cPtr->n;j++)
				if(twoDimArr[i][j]!=0)	//若元素的值不为0，则存入三元组表
				{
					cPtr->dataPtr[len].i = i;
					cPtr->dataPtr[len].j = j;
					cPtr->dataPtr[len].v = twoDimArr[i][j];
					len++;
					if(len%TABLE_ELEMENT_SIZE==0)   //三元组表存储空间已满，追加存储空间
						cPtr->dataPtr = realloc(cPtr->dataPtr,sizeof(Element)*(TABLE_INCREMENT+len));
 				}
			free(*(twoDimArr+i));   //释放动态申请的内存
		}
		cPtr->t=len;
		free(twoDimArr);    //释放动态申请的内存
	}
}
void PrintMatrix(Table matr)	//打印矩阵
{
	int iMatrix,jMatrix,vMatrix,t,k,num;
	int row=matr.m,col=matr.n;
	//三元组表形式
    printf("按三元组表形式输出：\ni	j	v\n");
    if(matr.t==0)
		printf("空\n");
	else
    	for(t=0;t<matr.t;t++)
    	{
			iMatrix = matr.dataPtr[t].i;
			jMatrix = matr.dataPtr[t].j;
			vMatrix = matr.dataPtr[t].v;
			printf("%d	%d	%d\n",iMatrix,jMatrix,vMatrix);
		}
    //矩阵形式
	printf("\n按矩阵形式输出：\n");
	for(k=1,t=0;k<=row*col;k++)
	{
		num = (matr.dataPtr[t].i-1)*col + matr.dataPtr[t].j;
		if(k==num)
			printf("%d	",matr.dataPtr[t++].v);
		else
			printf("0	");
		if(k%col==0)
			printf("\n\n");
	}
}

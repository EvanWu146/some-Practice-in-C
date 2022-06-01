#include<stdio.h>
#include<stdlib.h>
#include"headfiles.h"
#define TABLE_ELEMENT_SIZE 5
#define TABLE_INCREMENT 5
void InputMatrix(Table *matrixPtr)  //输入矩阵，存入三元组表
{
	int row,col,i,num,len;
	scanf("%d %d",&row,&col);
	matrixPtr->m = row;
	matrixPtr->n = col;
	matrixPtr->dataPtr = malloc(sizeof(Element)*TABLE_ELEMENT_SIZE);
	if(matrixPtr->dataPtr != NULL)
	{
		printf("请逐行输入矩阵元素：\n");
 		for(i=0,len=0;i<row*col;i++)
		{
		
			scanf("%d",&num);
			if(num != 0)	//若元素的值不为0，则存入三元组表
			{
				matrixPtr->dataPtr[len].i = i/col+1;
				matrixPtr->dataPtr[len].j = i%col+1;
				matrixPtr->dataPtr[len].v = num;
				len++;
				if(len%TABLE_ELEMENT_SIZE == 0) //三元组表存储空间已满，追加存储空间
					matrixPtr->dataPtr = realloc(matrixPtr->dataPtr,sizeof(Element)*(TABLE_INCREMENT+len));
			}
		}
		matrixPtr->t = len;
	}
}
int CanOperateOrNot(Table a,Table b)    //判断两个矩阵能否做运算，若不能，说明原因。返回判断结果。
{
	int flag=0;
	printf("\n==================================================\n");
	//判断能否做加法运算
	if(a.m==b.m && a.n==b.n)
	{
		flag+=1;
		printf("两个矩阵能做加法运算。\n");
	}
	else if(a.m!=b.m)
		printf("由于两个矩阵行数不相等，不能做加法运算。\n");
	else 
		printf("由于两个矩阵列数不相等，不能做加法运算。\n");
    //判断能否做乘法运算
	if(a.n==b.m)
	{
		flag+=2;
		printf("两个矩阵能做乘法运算。\n");
	}
	else
		printf("由于A矩阵的列数和B矩阵的行数不相等，不能做乘法运算。\n");
	return flag;
}

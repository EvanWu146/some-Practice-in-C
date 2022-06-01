#include"headfiles.h"
#include<stdio.h> 
#include<stdlib.h>
#define NEITHER 0   //两种运算都不能进行
#define ADDITION 1  //能进行加法运算
#define MULTIPLICATION 2    //能进行乘法运算
#define BOTH 3  //两种运算都能进行
int main()
{
	int m,n,flag;
	Table matrixA,matrixB,matrixAddi,matrixMult;
	printf("请输入A矩阵的行数和列数：\n");
	InputMatrix(&matrixA);
	printf("请输入B矩阵的行数和列数：\n");
	InputMatrix(&matrixB);
	flag = CanOperateOrNot(matrixA,matrixB);
	if(flag==ADDITION || flag==BOTH)
	{
		Addition(&matrixA,&matrixB,&matrixAddi);
		printf("\n==================================================\n");
		printf("两个矩阵相加得到的矩阵如下：\n\n");
		PrintMatrix(matrixAddi);
	}
	if(flag==MULTIPLICATION || flag==BOTH)
	{
		Multiplication(&matrixA,&matrixB,&matrixMult);
		printf("\n==================================================\n");
		printf("两个矩阵相乘得到的矩阵如下：\n\n");
		PrintMatrix(matrixMult);
	}
	free(matrixAddi.dataPtr);
	free(matrixMult.dataPtr);
}

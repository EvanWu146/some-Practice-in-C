#include"headfiles.h"
#include<stdio.h>
#include<stdlib.h>
void Addition(Table *aPtr,Table *bPtr,Table *cPtr)  //让两个矩阵做加法运算，并将所得矩阵存入三元组表
{
	int i,j,t;
	int Row = aPtr->m, Col = aPtr->n;
	int **twoDimArr=NULL;
	twoDimArr=malloc(sizeof(int*)*(Row+1));
	cPtr->m = Row;
	cPtr->n = Col;
	//创建二元动态数组来表示C矩阵，并将1~Row行和1~Col列的元素置零
	for(i=1;i<=Row;i++)
	{
		*(twoDimArr+i)=malloc(sizeof(int)*(Col+1));
		for(j=1;j<=Col;j++)
			twoDimArr[i][j]=0;
	}
	//将A矩阵中元素加给C矩阵相应元素
	for(t=0;t<aPtr->t;t++)
	{
		i = aPtr->dataPtr[t].i;
		j = aPtr->dataPtr[t].j;
		twoDimArr[i][j] += aPtr->dataPtr[t].v;
	}
	//将B矩阵中元素加给C矩阵相应元素
	for(t=0;t<bPtr->t;t++)
	{
		i = bPtr->dataPtr[t].i;
		j = bPtr->dataPtr[t].j;
		twoDimArr[i][j] += bPtr->dataPtr[t].v;
	}
	ArrayToTable(twoDimArr,cPtr);
}
void Multiplication(Table *aPtr,Table *bPtr,Table *cPtr)    //让两个矩阵做乘法运算，并将所得矩阵存入三元组表
{
	int aRow = aPtr->m, bRow = bPtr->m, bCol = bPtr->n;
	int iA,jA,iB,jB,i,j,tA,tB;
	int **twoDimArr=NULL;
	twoDimArr=malloc(sizeof(int*)*(aRow+1));
	cPtr->m = aRow;
	cPtr->n = bCol;
	//创建二元动态数组来表示C矩阵，并将1~Row行和1~Col列的元素置零
	for(i=1;i<=aRow;i++)
	{
		*(twoDimArr+i)=malloc(sizeof(int)*(bCol+1));
		for(j=1;j<=bCol;j++)
			twoDimArr[i][j]=0;
	}
	/*设a为A矩阵中的任意元素，其行标为iA，列标为jA；
	b为B矩阵中的任意元素，其行标为iB，列标为jB。
	若jA等于iB，则将a*b的值加给C矩阵中行标为iA列标为jB的元素*/
	for(tA=0;tA<aPtr->t;tA++)
	{
		iA = aPtr->dataPtr[tA].i;
		jA = aPtr->dataPtr[tA].j;
		for(tB=0;tB<bPtr->t && bPtr->dataPtr[tB].i<=jA;tB++)
		{
			iB = bPtr->dataPtr[tB].i;
			jB = bPtr->dataPtr[tB].j;
			if(jA==iB)
				twoDimArr[iA][jB] += aPtr->dataPtr[tA].v * bPtr->dataPtr[tB].v;
		}
	}
	ArrayToTable(twoDimArr,cPtr);
}

#include"headfiles.h"
#include<stdio.h>
#include<stdlib.h>
void Addition(Table *aPtr,Table *bPtr,Table *cPtr)  //�������������ӷ����㣬�������þ��������Ԫ���
{
	int i,j,t;
	int Row = aPtr->m, Col = aPtr->n;
	int **twoDimArr=NULL;
	twoDimArr=malloc(sizeof(int*)*(Row+1));
	cPtr->m = Row;
	cPtr->n = Col;
	//������Ԫ��̬��������ʾC���󣬲���1~Row�к�1~Col�е�Ԫ������
	for(i=1;i<=Row;i++)
	{
		*(twoDimArr+i)=malloc(sizeof(int)*(Col+1));
		for(j=1;j<=Col;j++)
			twoDimArr[i][j]=0;
	}
	//��A������Ԫ�ؼӸ�C������ӦԪ��
	for(t=0;t<aPtr->t;t++)
	{
		i = aPtr->dataPtr[t].i;
		j = aPtr->dataPtr[t].j;
		twoDimArr[i][j] += aPtr->dataPtr[t].v;
	}
	//��B������Ԫ�ؼӸ�C������ӦԪ��
	for(t=0;t<bPtr->t;t++)
	{
		i = bPtr->dataPtr[t].i;
		j = bPtr->dataPtr[t].j;
		twoDimArr[i][j] += bPtr->dataPtr[t].v;
	}
	ArrayToTable(twoDimArr,cPtr);
}
void Multiplication(Table *aPtr,Table *bPtr,Table *cPtr)    //�������������˷����㣬�������þ��������Ԫ���
{
	int aRow = aPtr->m, bRow = bPtr->m, bCol = bPtr->n;
	int iA,jA,iB,jB,i,j,tA,tB;
	int **twoDimArr=NULL;
	twoDimArr=malloc(sizeof(int*)*(aRow+1));
	cPtr->m = aRow;
	cPtr->n = bCol;
	//������Ԫ��̬��������ʾC���󣬲���1~Row�к�1~Col�е�Ԫ������
	for(i=1;i<=aRow;i++)
	{
		*(twoDimArr+i)=malloc(sizeof(int)*(bCol+1));
		for(j=1;j<=bCol;j++)
			twoDimArr[i][j]=0;
	}
	/*��aΪA�����е�����Ԫ�أ����б�ΪiA���б�ΪjA��
	bΪB�����е�����Ԫ�أ����б�ΪiB���б�ΪjB��
	��jA����iB����a*b��ֵ�Ӹ�C�������б�ΪiA�б�ΪjB��Ԫ��*/
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

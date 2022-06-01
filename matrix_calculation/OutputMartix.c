#include<stdio.h>
#include"headfiles.h"
#include<stdlib.h>
#define TABLE_ELEMENT_SIZE 5
#define TABLE_INCREMENT 5
void ArrayToTable(int **twoDimArr,Table *cPtr)  //���ö�ά����洢�ľ�������Ԫ���洢����
{
	int i,j,len;
	cPtr->dataPtr = malloc(sizeof(Element)*TABLE_ELEMENT_SIZE);
	if(cPtr->dataPtr!=NULL)
	{
		for(i=1,len=0;i<=cPtr->m;i++)
		{
			for(j=1;j<=cPtr->n;j++)
				if(twoDimArr[i][j]!=0)	//��Ԫ�ص�ֵ��Ϊ0���������Ԫ���
				{
					cPtr->dataPtr[len].i = i;
					cPtr->dataPtr[len].j = j;
					cPtr->dataPtr[len].v = twoDimArr[i][j];
					len++;
					if(len%TABLE_ELEMENT_SIZE==0)   //��Ԫ���洢�ռ�������׷�Ӵ洢�ռ�
						cPtr->dataPtr = realloc(cPtr->dataPtr,sizeof(Element)*(TABLE_INCREMENT+len));
 				}
			free(*(twoDimArr+i));   //�ͷŶ�̬������ڴ�
		}
		cPtr->t=len;
		free(twoDimArr);    //�ͷŶ�̬������ڴ�
	}
}
void PrintMatrix(Table matr)	//��ӡ����
{
	int iMatrix,jMatrix,vMatrix,t,k,num;
	int row=matr.m,col=matr.n;
	//��Ԫ�����ʽ
    printf("����Ԫ�����ʽ�����\ni	j	v\n");
    if(matr.t==0)
		printf("��\n");
	else
    	for(t=0;t<matr.t;t++)
    	{
			iMatrix = matr.dataPtr[t].i;
			jMatrix = matr.dataPtr[t].j;
			vMatrix = matr.dataPtr[t].v;
			printf("%d	%d	%d\n",iMatrix,jMatrix,vMatrix);
		}
    //������ʽ
	printf("\n��������ʽ�����\n");
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

#include<stdio.h>
#include<stdlib.h>
#include"headfiles.h"
#define TABLE_ELEMENT_SIZE 5
#define TABLE_INCREMENT 5
void InputMatrix(Table *matrixPtr)  //������󣬴�����Ԫ���
{
	int row,col,i,num,len;
	scanf("%d %d",&row,&col);
	matrixPtr->m = row;
	matrixPtr->n = col;
	matrixPtr->dataPtr = malloc(sizeof(Element)*TABLE_ELEMENT_SIZE);
	if(matrixPtr->dataPtr != NULL)
	{
		printf("�������������Ԫ�أ�\n");
 		for(i=0,len=0;i<row*col;i++)
		{
		
			scanf("%d",&num);
			if(num != 0)	//��Ԫ�ص�ֵ��Ϊ0���������Ԫ���
			{
				matrixPtr->dataPtr[len].i = i/col+1;
				matrixPtr->dataPtr[len].j = i%col+1;
				matrixPtr->dataPtr[len].v = num;
				len++;
				if(len%TABLE_ELEMENT_SIZE == 0) //��Ԫ���洢�ռ�������׷�Ӵ洢�ռ�
					matrixPtr->dataPtr = realloc(matrixPtr->dataPtr,sizeof(Element)*(TABLE_INCREMENT+len));
			}
		}
		matrixPtr->t = len;
	}
}
int CanOperateOrNot(Table a,Table b)    //�ж����������ܷ������㣬�����ܣ�˵��ԭ�򡣷����жϽ����
{
	int flag=0;
	printf("\n==================================================\n");
	//�ж��ܷ����ӷ�����
	if(a.m==b.m && a.n==b.n)
	{
		flag+=1;
		printf("�������������ӷ����㡣\n");
	}
	else if(a.m!=b.m)
		printf("��������������������ȣ��������ӷ����㡣\n");
	else 
		printf("��������������������ȣ��������ӷ����㡣\n");
    //�ж��ܷ����˷�����
	if(a.n==b.m)
	{
		flag+=2;
		printf("�������������˷����㡣\n");
	}
	else
		printf("����A�����������B�������������ȣ��������˷����㡣\n");
	return flag;
}

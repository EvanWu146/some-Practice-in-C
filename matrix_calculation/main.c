#include"headfiles.h"
#include<stdio.h> 
#include<stdlib.h>
#define NEITHER 0   //�������㶼���ܽ���
#define ADDITION 1  //�ܽ��мӷ�����
#define MULTIPLICATION 2    //�ܽ��г˷�����
#define BOTH 3  //�������㶼�ܽ���
int main()
{
	int m,n,flag;
	Table matrixA,matrixB,matrixAddi,matrixMult;
	printf("������A�����������������\n");
	InputMatrix(&matrixA);
	printf("������B�����������������\n");
	InputMatrix(&matrixB);
	flag = CanOperateOrNot(matrixA,matrixB);
	if(flag==ADDITION || flag==BOTH)
	{
		Addition(&matrixA,&matrixB,&matrixAddi);
		printf("\n==================================================\n");
		printf("����������ӵõ��ľ������£�\n\n");
		PrintMatrix(matrixAddi);
	}
	if(flag==MULTIPLICATION || flag==BOTH)
	{
		Multiplication(&matrixA,&matrixB,&matrixMult);
		printf("\n==================================================\n");
		printf("����������˵õ��ľ������£�\n\n");
		PrintMatrix(matrixMult);
	}
	free(matrixAddi.dataPtr);
	free(matrixMult.dataPtr);
}

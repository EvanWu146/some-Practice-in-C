typedef struct tuple{   //������Ԫ����Ԫ�ص�����
	int i,j,v;
}Element;
typedef struct sparmattp{   //������Ԫ���
	int m,n,t;
	Element *dataPtr;
}Table;
void InputMatrix(Table *);
int CanOperateOrNot(Table ,Table);
void Addition(Table *,Table *,Table *);
void Multiplication(Table *,Table *,Table *);
void PrintMatrix(Table );
void ArrayToTable(int **,Table *);

typedef struct tuple{   //定义三元组表的元素的类型
	int i,j,v;
}Element;
typedef struct sparmattp{   //定义三元组表
	int m,n,t;
	Element *dataPtr;
}Table;
void InputMatrix(Table *);
int CanOperateOrNot(Table ,Table);
void Addition(Table *,Table *,Table *);
void Multiplication(Table *,Table *,Table *);
void PrintMatrix(Table );
void ArrayToTable(int **,Table *);

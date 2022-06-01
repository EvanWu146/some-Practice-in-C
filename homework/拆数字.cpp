#include<stdio.h>
int main()
{
	char a;
	int i;
	for(i=1;scanf("%c",&a)==1&&i<=9;i++){
		if(a<48||a>57)continue;
		if(a>=48&&a<=57){
			printf("%c ",a);
		}
	}
	printf("\n");
	return 0;
}

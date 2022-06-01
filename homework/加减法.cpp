#include<stdio.h>
main()
{
	int number1;
	int number2;
	int a;
	int b;
	
	scanf("%d",&number1);
	number2=number1+1;
	a=number1+number2;
	b=number1-number2;
	printf("The sum is %d and the difference is %d.\n",a,b);
	return 0;
}

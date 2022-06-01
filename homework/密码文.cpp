#include<stdio.h>
int main()
{
	char a,b;
	while(scanf("%c",&a)==1)
	{
		if((a<'A')||(a>'Z'&&a<'a')||(a>'z'))continue;
		if((a>='a'&&a<='w')||(a<='W'&&a>='A'))
		{
			b=a+3;
		}
		else if((a<='z'&&a>'w')||(a<='Z'&&a>'W'))
		{
			b=a-23;
		}
		printf("%c",b);
	}
	return 0;
	
}

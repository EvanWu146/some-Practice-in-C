#include<stdio.h>
int main(void)
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	if (
	((a>='a')&&(a<='z')||(a>='A')&&(a<='Z'))&&
	((b>='a')&&(b<='z')||(b>='A')&&(b<='Z'))&&
	((c>='a')&&(c<='z')||(c>='A')&&(c<='Z'))
	)
	{
		if(
		((b-a==1)||(a-b==1))&&((c-b==1)||(b-c==1))
		)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
		
	}
	else
	{
		printf("No");
	}
	return 0;
}

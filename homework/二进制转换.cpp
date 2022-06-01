#include<stdio.h>
int main()
{
	char ch;
	int a=0,b=2;
	double c=0;
	scanf("%c",&ch);
	while(ch<='9'&&ch>='0'){
		a=a*2+(ch-'0');
		scanf("%c",&ch);
	}
	if(ch=='.'){
		scanf("%c",&ch);
		while(ch!='#'){
			c=c+(double)(ch-'0')/b;
			b=b*2;
			scanf("%c",&ch);
		}
		printf("%lf",a+c);	
	}	
	else{
		printf("%d",a);
	}
	return 0;
}

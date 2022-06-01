#include<stdio.h>
int main()
{
	int i;
	char ch[i];
	
	for(i=1;i<=2;i++){
		scanf("%c",&ch[i]);
	}
	ch[1]=ch[1]+12;
	for(i=1;i<=2;i++){
		printf("%c",ch[i]);
	}
 } 

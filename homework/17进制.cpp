#include<stdio.h>
int main()
{
	int a,b=0;
	char ch;
	
	while(scanf("%c",&ch)==1){
		if(ch=='\n'){
			break;
		}
		else{
			a=ch-'a';
			b=b*17+a;
		}
	}
	printf("%d",b);
 } 

#include<stdio.h>

int main()
{
	int i,capital,lowercase,sum;
	char ch[100];
	scanf("%s",ch);
	
	for(capital='A';capital<='z';capital++){
		for(i=0,sum=0;ch[i]!='\0';i++){
			if(ch[i]==capital){
				sum++;
			}
	    }
	    if(sum!=0) printf("The character %c has presented %d times.\n",capital,sum);
	    if(capital=='Z') capital+=6;
	}
	return 0;
} 

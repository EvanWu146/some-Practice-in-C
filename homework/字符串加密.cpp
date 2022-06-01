#include<stdio.h>
int main()
{
	int i,change;
	char input[101],capital[27],lowercase[27];
	scanf("%s",input);
	scanf("%s",capital);
	scanf("%s",lowercase);
	for(i=0;input[i]!='\0';i++){
		if(input[i]!='z'&&input[i]!='Z')
			input[i]=input[i]+1;
		else input[i]=input[i]-25;
	}
	
	for(i=0;input[i]!='\0';i++){
		if(input[i]<='Z'&&input[i]>='A'){
			change=input[i]-'A';
			input[i]=capital[change];
		}
		if(input[i]<='z'&&input[i]>='a'){
			change=input[i]-'a';
			input[i]=lowercase[change];
		}
	}
	printf("%s",&input);
}


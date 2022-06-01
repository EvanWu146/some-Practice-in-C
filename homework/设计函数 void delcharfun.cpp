#include<stdio.h>
#include<string.h>
void delchar(char *str,char ch)
{
	int i,k;
	for(i=0;str[i]!='\0';i++){
		if(str[i]==ch){
			for(k=i;str[k+1]!='\0';k++){
				str[k]=str[k+1];
			}
			str[k]='\0';
		}	
	}
}
int main()
{
	char ch,str[101];
	gets(str);
	scanf("%c",&ch);
	delchar(str,ch);
	printf("%s",str);
}

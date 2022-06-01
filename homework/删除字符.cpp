#include<stdio.h>
#include<string.h>
void delcharfun(char *str,char ch)
{
	int i,j;
	for(i=0;str[i]!='\0';i++){
		if(str[i]==ch&&str[i+1]!='\0'){
			for(j=i;str[j+1]!='\0';j++){
				str[j]=str[j+1];
			}
			str[j]='\0';
			i--;
		}
		else if(str[i]==ch&&str[i+1]=='\0'){
			str[i]='\0';
		}
	}
} 
int main(){
	char str[101],ch;
	scanf("%s",str);
	getchar();
	scanf("%c",&ch);
	delcharfun(str,ch);
	printf("%s\n",str);
}

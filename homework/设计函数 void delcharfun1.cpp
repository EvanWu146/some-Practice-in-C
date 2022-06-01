#include<stdio.h>
void delcharfun(char *str,char ch){
	int i;
	for(i=0;*(str+i)!=0;i++){
		if(*(str+i)==ch) *(str+i)=' ';
	}
}
int main(){
	char string[101],ch;
	int i;
	scanf("%s",string);
	getchar();
	scanf("%c",&ch);
	delcharfun(string,ch);
	for(i=0;*(string+i)!=0;i++){
		if(*(string+i)!=' ') printf("%c",*(string+i)); 
	}
	printf("\n");
}

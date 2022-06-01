#include<stdio.h>
#include<string.h>
void printword(char *loc){
	int i;
	char *locs;
	for(;*loc==' ';loc++);//跳过开始的一连串空格 
	locs=loc;//记录单词首字母位置 
	for(;*loc!=' ';loc++);//使loc指向单词后第一个空格 
	*loc='\0';//改空格为0 
	printf("%s",locs);//输出字符串 
	for(loc++;*loc==' ';loc++);//跳过单词后的连续空格 
	if(*loc!='\0') {
		printf("\n");//有下一个单词则换行，重新调用函数 
		printword(loc);
	}
} 
int main()
{
	char str[100001],*s;
	int len;
	gets(str);
	len=strlen(str);
	str[len]=' ';
	str[len+1]='\0';
	printword(str);
}

#include<stdio.h>
#include<string.h>
void printword(char *loc){
	int i;
	char *locs;
	for(;*loc==' ';loc++);//������ʼ��һ�����ո� 
	locs=loc;//��¼��������ĸλ�� 
	for(;*loc!=' ';loc++);//ʹlocָ�򵥴ʺ��һ���ո� 
	*loc='\0';//�Ŀո�Ϊ0 
	printf("%s",locs);//����ַ��� 
	for(loc++;*loc==' ';loc++);//�������ʺ�������ո� 
	if(*loc!='\0') {
		printf("\n");//����һ���������У����µ��ú��� 
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

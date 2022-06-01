#include<stdio.h>
void Task_1(FILE *fptr){
	char ch;
	int capital=0,lowercase=0,digit=0,others=0;
	while(!feof(fptr)){
		ch=fgetc(fptr);
		if(ch<='Z'&&ch>='A'){
			capital++;
		}
		else if(ch<='z'&&ch>='a'){
			lowercase++;
		}
		else if(ch<='9'&&ch>='0'){
			digit++;
		}
		else  others++;
	}
	printf("Task1:\ncapital: %d\nlowercase: %d\ndigit: %d\nothers: %d",capital,lowercase,digit,others-1);
}
void Task_2(FILE *fptr){
	char ch;
	int line=0,ch_MAX=0,ch_MIN=0,ch_TEMP=0;
	while(!feof(fptr)){
		ch=fgetc(fptr);
		if(ch!='\n'){
			ch_TEMP++;
		}
		else{
			line++;
			if(ch_MAX==0){
				ch_MAX=ch_TEMP;
				ch_MIN=ch_TEMP;
			}
			else if(ch_TEMP>=ch_MAX){
				ch_MAX=ch_TEMP;
			}
			else if(ch_TEMP<=ch_MIN){
				ch_MIN=ch_TEMP;
			}
			ch_TEMP=0;
		}
	}
	line++;
	printf("Task2:\nline: %d\n%d characters in max line.\n%d characters in min line.",line,ch_MAX,ch_MIN);
}
void Task_3(FILE *fptr){
	int cap_NUM[25]={0},low_NUM[25]={0},i=0;
	char ch=0;
	while(!feof(fptr)){
		ch=fgetc(fptr);
		if(ch>='A'&&ch<='Z'){
			cap_NUM[ch-'A']++;
		}
		else if(ch>='a'&&ch<='z'){
			low_NUM[ch-'a']++;
		}
	}
	rewind(fptr);
	printf("Task3:\nCAPITAL:\n");
	while(i<=25){
		printf("%c:%d\n",'A'+i,cap_NUM[i]);
		i++;
	}
	i=0;
	rewind(fptr);
	printf("LOWERCASE:\n");
	while(i<=25){
		printf("%c:%d\n",'a'+i,low_NUM[i]);
		i++;
	}
}
int main()
{
	FILE *fp;
	int task_NUM;
	if((fp=fopen("dict.txt","r"))!=NULL){
		scanf("%d",&task_NUM);
		if(task_NUM==1){
			Task_1(fp);
		}
		else if(task_NUM==2){
			Task_2(fp);
		}
		else if(task_NUM==3){
			Task_3(fp);
		}
	}
	fclose(fp);
}

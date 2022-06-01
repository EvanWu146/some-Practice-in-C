#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<string.h>

void instead_shieldWORDS(){
	int numofWORDS,numofLINES=0;
	char shield_WORDS[10][10],ch,article[100][110],shield[9]="!@#$%^&*";
	int i=0,j=0,k=0,m=0,s=0,pass,flag=1,flag1=1;
	
	FILE *fptr=fopen("data3.txt","r");
	if(fptr!=NULL){
		while(!feof(fptr)){	
			fgets(shield_WORDS[i],10,fptr);
			i++;
		}// store the shield words
		numofWORDS=i;
		for(j=i;j>=0;j--){
			for(i=0;shield_WORDS[j][i]!='\0';i++);
			shield_WORDS[j][i-1]='\0';
		}//remove the '\n'
		j=0;
		while(flag){
			for(i=0;(article[j][i]=getchar())!=EOF&&article[j][i]!='\n';i++);
			if(article[j][i]==EOF){
				article[j][i]='\0';
				flag=0;
			}
			else if(article[j][i]=='\n') article[j][i+1]='\0';
			j++;
		}//input the article
		numofLINES=j;
		for(i=0;i<numofLINES;i++){//长字符串的循环 
			for(j=0;j<strlen(article[i]);j++){//进行单行逐字符检测 
				flag1=0;//初始化标记——用于检测是否有不和谐字符 
				for(k=0;k<numofWORDS;k++){//逐个屏蔽词进行检测 
					char temp_STR[strlen(shield_WORDS[k])+1];
					if(article[i][j]==shield_WORDS[k][0]){//原字符串的某个字符与某屏蔽词汇首字符相同 
						m=j;
						for(s=0;s<strlen(shield_WORDS[k]);s++){
							temp_STR[s]=article[i][m];
							m++;
						}
						temp_STR[strlen(shield_WORDS[k])]='\0';//将字符串复制到中间字符串 
						if(strcmp(temp_STR,shield_WORDS[k])==0){
							printf("%s",shield);
							j=m-1;
							flag1=1;
						}//屏蔽并跳过不和谐字符 
					}
				}
				if(flag1==0){
					printf("%c",article[i][j]);
				}
			}
		}
		fclose(fptr);
	}
	else printf("error!!!!!");
	
}

int main()
{
	instead_shieldWORDS();
}

#include<stdio.h>
#include<strings.h>
int main()
{
	int str2len=0,i,j,sum=0,i1;
	int flag,m;
    char str1[100],str2[100],temp[100];
	gets(str1);
	gets(str2);
	for(i=0;str2[i]!='\0';i++){
		str2len++;
	}
	

	for(i=0;str1[i]!='\0';i++){
		for(j=0,i1=i;str1[i1]!='\0'&&j+1<=str2len;j++,i1++){
			temp[j]=str1[i1];
		}
		temp[j]='\0';
		for(m=0,flag=0;m<=j-1;m++){
			if(temp[m]!=str2[m]){
				flag=1;
			}
		}
		if(m!=str2len) flag=1;
		if(flag==0){
			sum++;
		}
	}
	printf("%d",sum);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[100101],*ptr[100],*pointer,tem;
	int i,n,j,temp[100],mid;
	scanf("%d",&n);
	getchar();
	
	for(i=0,j=0;i<=n-1;i++){
		gets(&str[j]);
		ptr[i]=&str[j];
		j=strlen(str);
		str[j]=' ';
		j++;
	}
	for(i=0;i<=n-1;i++){
		*(ptr[i]-1)=0;
	}
	for(i=1;i<=n-1;i++){
		for(j=0;j<=n-i-1;j++){
			if(strcmp(ptr[j],ptr[j+1])>0){
				pointer=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=pointer;
			}
		}
	}
	for(i=0;i<=n-1;i++) puts(ptr[i]);
}


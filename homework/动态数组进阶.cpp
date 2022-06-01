#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *a,str[1000],**ptr,*temp;
	int n,i,j;
	scanf("%d",&n);
	ptr=(char **)malloc(sizeof(char *)*n);
	getchar(); 
	for(i=0;i<=n-1;i++){
		gets(str);
		a=(char *)malloc(sizeof(char)*strlen(str));
		strcpy(a,str);
		ptr[i]=a;
		a=NULL;
		
	}
	for(i=1;i<=n-1;i++){
		for(j=0;j<=n-i-1;j++){
			if(strcmp(ptr[j],ptr[j+1])>0){
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
			}
		}
	}
	for(i=0;i<=n-1;i++) puts(ptr[i]);
	free(a);
	free(ptr);
}


#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char string[200][101],temp[101];
	scanf("%d",&n);
	getchar();
	for(i=0;i<=n-1;i++){
		gets(string[i]);
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=n-i;j++){
			if(strcmp(string[j],string[j-1])<0){
				strcpy(temp,string[j-1]);
				strcpy(string[j-1],string[j]);
				strcpy(string[j],temp);
			}
		}
	}
	for(i=0;i<=n-1;i++) printf("%s\n",string[i]);
	
}



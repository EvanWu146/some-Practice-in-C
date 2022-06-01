#include<stdio.h>
#include<string.h>
char *locatesubstr(char *str1,char *str2){
	int i,m,k,flag=2;
	for(i=0;str1[i]!='\0';i++){
		if(str1[i]==str2[0]){
			for(k=i;str1[k]!='\0';k++);
			if(k>=strlen(str2)){
				for(m=0,flag=0;str2[m]!='\0';m++){
					if(str2[m]!=str1[m+i]){
						flag=1;
					}
				}
				if(flag==0) return &str1[i];
			}	
		}
	}
	if(flag!=0) return NULL;
}
int main(){
	char str1[501],str2[501];
	char *loc;
	gets(str1);
	gets(str2);
	
	loc=locatesubstr(str1,str2);
	if(loc!=NULL) printf("%s",loc);
	else printf("NULL!");
}

#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	int left=0,right=0;
	int flag=0;
	char c[101];
	
	scanf("%s",c);
	i=strlen(c);
	for(j=0;j<=i-1;j++){
		if(c[j]=='(') left++;
		if(c[j]==')') right++;
		if(right>left) flag=1;
	} 
	printf("%d %d",left,right);
	if(flag==1||(flag==0&&left!=right)) printf("parentheses do not match!\n");
	else if(flag==0&&left==right) printf("parentheses match!\n");
}

#include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i,j;
	char a[100000]={'\0'},**m,*b;
	scanf("%d",&n);
	m=malloc(sizeof(char*)*n);
	*m=a;
	getchar();
	for(i=0,j=0;j<n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')a[i]='\0',*(m+(++j))=&a[i+1];
	}
	for(i=n-1;i>0;i--)
		for(j=0;j<i;j++)
		if(strcmp(*(m+j),*(m+j+1))>0)b=*(m+j),*(m+j)=*(m+j+1),*(m+j+1)=b;
	for(i=0;i<n;i++)
	puts(*(m+i));
	free(m);
}

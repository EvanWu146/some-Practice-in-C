#include<stdio.h>
int main()
{
	int a,b,c,x,y,i;
	scanf("%d%d%d",&a,&b,&c);
	y=0;
	i=0;
	for(x=0;x<=c/a;x++)
	{
		for(y=0;y<=c/b;y++){
			if(a*x+b*y==c){
				i++;
			}
		}
	}
	printf("%d",i);
}

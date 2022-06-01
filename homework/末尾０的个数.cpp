#include<stdio.h>
int main()
{
	long int x,y,i2=0,T,i5=0,x1,y1,i;
	y=1; 
	scanf("%ld",&x);/*输入第一个数的值*/ 
	while(x!=0){
		for(x1=x;x1%2==0;x1=x1/2,i2++);
		for(x1=x;x1%5==0;x1=x1/5,i5++);	
		scanf("%ld",&x);
	}
	if(i2>=i5){
		i=i5;
	}
	else{
		i=i2;
	}
	printf("%ld",i);
}

#include<stdio.h>
int fun1(int);
int fun2(int);
int fun3(int);
int fun4(int);
main()
{
	int x,y;
	scanf("%d",&x);
	if(x<1){
		y=fun1(x);
	}
	if(x>=1&&x<=10){
		y=fun2(x);
	}
	if(x>10&&x<=100){
		y=fun3(x);
	}
	if(x>100){
		y=fun4(x);
	}
	printf("The result is:y=%d",y);
} 
int fun1(int y){
	return y;
}
int fun2(int y){
	return 2*y-1;
}
int fun3(int y){
	return 3*y-11;
}
int fun4(int y){
	return y*y-24;
}

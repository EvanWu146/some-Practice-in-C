#include<stdio.h>
int main()
{
	int a,b,c,d;
	int A,B,C,D;
	int n,f;
	scanf("%d%d",&n,&f);
	
	if(f==1){
		d=n%10;
		c=(n%100-d)/10;
		b=(n%1000-d-c)/100;
		a=(n-n%1000)/1000;
		A=(c+7)%10;
		B=(d+7)%10;
		C=(a+7)%10;
		D=(b+7)%10;
		printf("After encrypting the number is %d%d%d%d",A,B,C,D);
	}
	if(f==0){
		d=n%10;
		c=(n%100-d)/10;
		b=(n%1000-d-c)/100;
		a=(n-n%1000)/1000;
		if(c+3>=10){
			A=(c+3)%10;
		}
		else{
			A=c+3;
		}
		if(d+3>=10){
			B=(d+3)%10;
		}
		else{
			B=d+3;
		}
		if(a+3>=10){
			C=(a+3)%10;
		}
		else{
			C=a+3;
		}
		if(b+3>=10){
			D=(b+3)%10;
		}
		else{
			D=b+3;
		}
		printf("After decrypting the number is %d%d%d%d",A,B,C,D);
	}
	return 0; 
}

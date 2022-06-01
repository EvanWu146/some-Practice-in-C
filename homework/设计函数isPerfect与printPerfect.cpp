#include<stdio.h>
int isperfect(int);
void printfperfect(int);
main()
{
	int a,b,i,s=0;
	scanf("%d%d",&a,&b);
	i=a;
	while(i<=b){
		if(isperfect(i)==1){
			printfperfect(i);
			s=s+1;
		}
		i++;
	}
	printf("The total number is %d.",s);
} 
int isperfect(int n)
{
	int i=1,s=0;
	while(i<n){
		if(n%i==0)
			s=s+i;
		i=i+1;
	}
	if(n==s){
		return 1;
	}
	else{
		return 0;
	}
}
void printfperfect(int n)
{
	int i=1,s=0,j=0;
	printf("%d=",n);
	while(i<n){
		if(n%i==0&&j==0){
			printf("%d",i);
			j++;
		}
		else if(n%i==0&&j!=0){
			printf("+%d",i);
		}
		i++;
	}
	printf("\n");
}

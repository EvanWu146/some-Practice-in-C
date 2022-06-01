#include<stdio.h>
int main()
{
	int score;
	scanf("%d",&score);
	if((score<=100)&&(score>=90))
	{
		printf("A");
	}
	if((score<90)&&(score>=80))
	{
		printf("B");
	}
	if((score<80)&&(score>=70))
	{
		printf("C");
	}
	if((score<70)&&(score>=60))
	{
		printf("D");
	}
	if((score<0)||(score>100))
	{
		printf("The score is out of range!"); 
	}
	if((score<60)&&(score>=0))
	{
		printf("E");
	}
	return 0;
}

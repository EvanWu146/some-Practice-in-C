#include<stdio.h>
int main()
{
	int y,m,d;
	scanf("%d%d",&y,&m);
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
		d=31;
	}
	if(m==4||m==6||m==9||m==11){
		d=30;
	}
	if(m==2){
		if((y%100!=0&&y%4==0)||(y%100==0&&y%400==0)){
			d=29;
		}
		else{
			d=28;
		}
	}	
	printf("There are %d days in month %d year %d.",d,m,y);
 } 

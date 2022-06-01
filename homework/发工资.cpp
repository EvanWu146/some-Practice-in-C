#include<stdio.h>
int main()
{
	int salary;
	int hundred,fifty,twenty,ten,five,two,one;
	scanf("%d",&salary);
	
	hundred=salary/100;
	fifty=(salary%100)/50;
	twenty=(salary%50)/20;
	ten=(salary-fifty*50-hundred*100-twenty*20)/10;
	five=(salary-fifty*50-hundred*100-twenty*20-ten*10)/5;
	two=(salary-fifty*50-hundred*100-twenty*20-ten*10-five*5)/2;
	one=(salary-fifty*50-hundred*100-twenty*20-ten*10-five*5-two*2)/1;
	
	if(hundred!=0){
		printf("%d:%d\n",100,hundred);
	}	
	if(fifty!=0){
		printf("%d:%d\n",50,fifty);
	}
	if(twenty!=0){
		printf("%d:%d\n",20,twenty);
	}
	if(ten!=0){
		printf("%d:%d\n",10,ten);
	}
	if(five!=0){
		printf("%d:%d\n",5,five);
	}
	if(two!=0){
		printf("%d:%d\n",2,two);
	}
	if(one!=0){
		printf("%d:%d\n",1,one);
	}
	 
}

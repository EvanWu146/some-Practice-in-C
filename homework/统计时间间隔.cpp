#include<stdio.h>
int main()
{
	int T,m,t=2;
	int x,y,x1,y1;
	scanf("%d",&T);
	while(t<=2*T){
		scanf("%d:%d",&x,&y);
		scanf("%d:%d",&x1,&y1);
		
		m=(x1-x)*60+y1-y;
		if(m<0){
			m+=1440;
		}
		printf("%d\n",m);
		t=t+2;
	} 
	return 0;
} 

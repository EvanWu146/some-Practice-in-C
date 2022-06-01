#include<stdio.h>
int main()
{
	int T,t=1,y;
	int a,b,c,d,e;
	int i,j,k,l,m;
	scanf("%d",&T);
	while(t<=T){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		y=0;
		for(i=-1;i<=1;i++){
			for(j=-1;j<=1;j++){
				for(k=-1;k<=1;k++){
					for(l=-1;l<=1;l++){
						for(m=-1;m<=1;m++){
							if(i*a+j*b+k*c+l*d+m*e==24){
								y=1;
							}
							
						}
					}
				}
			}
		}
		if(y==1){
			printf("YES\n");
		}
		else printf("NO\n"); 
		t++;
	}
	return 0;
}

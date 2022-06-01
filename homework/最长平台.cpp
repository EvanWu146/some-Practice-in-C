#include<stdio.h>
int main()
{
	int n,len,i,form,lenmax;
	scanf("%d",&n);
	int platform[n];
	
	for(i=0;i<=n-1;i++){
		scanf("%d",&platform[i]);
	} 
	form=platform[0];
	lenmax=1;
	for(i=1,len=1;i<=n;i++){
		
		if(form==platform[i]){
			len++;
		}
		else{
			if(len>lenmax) lenmax=len;
			len=1;
		}
		form=platform[i];
	}
	printf("%d\n",lenmax);
}


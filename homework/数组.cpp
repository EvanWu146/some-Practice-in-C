#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	double a[n],max,min,mid;
	
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	max=a[1];
	min=a[1];
	for(i=2;i<=n;i++){
		if(a[i]>max){
			max=a[i];
		}
		else if(a[i]<min){
			min=a[i];
		}
		else if(a[i]>min&&a[i]<max){
		}
	}
	mid=(max+min)/2.0;
	for(i=1;i<=n;i++){
		a[i]=a[i]-mid;
	}
	
	for(i=1;i<=n;i++){
		printf("%.2lf",a[i]);
		if(i!=n){
			printf(" ");
		}
		else{
		}
	}
	
	return 0;
}

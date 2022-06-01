#include<stdio.h>
int summ(int array[100],int loc){
	int sum,j;
	for(j=0,sum=0;j<=loc;j++){
		if(array[j]<array[loc]) sum++;
	}
	return sum;
}
int main()
{
	int a[100],n,i,j,temp,flag,sum,b[100];
	scanf("%d",&n);
	scanf("%d",&flag);
	
	
	if(flag==1){
		for(i=0;i<=n-1;i++) scanf("%d",&a[i]);
		b[0]=0;
		for(i=1;i<=n-1;i++){
			sum=summ(a,i);
			b[i]=sum;
		}
		for(i=0;i<=n-1;i++) printf("%d ",b[i]);
	}
	if(flag==2){
		for(i=0;i<=n-1;i++) scanf("%d",&b[i]);
		for(i=0;i<=n-1;i++) a[i]=i+1;
		for(i=1;i<=n-2;i++){
			for(j=1;b[i]!=summ(a,i);j++){
				temp=a[i+j];
				a[i+j]=a[i-j];
				a[i-j]=temp;
			}
		}
		for(i=0;i<=n-1;i++) printf("%d ",a[i]);
	}
	
}

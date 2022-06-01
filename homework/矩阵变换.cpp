#include<stdio.h>
void inputarray(long int array[][100],int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			scanf("%ld",&array[i][j]);
		}
	}/*input the array*/ 
} 
void findaverage(long int array[][100],int n,long int average[]){
	long int i,j,aver;
	for(i=0;i<=n-1;i++){
		for(j=0,aver=0;j<=n-1;j++){
			aver=array[i][j]+aver;
		}
		average[i]=aver/n;
	}//计算每行的平均值，然后将它们按原来的顺序存放到一个数组里 
}
void sortaverage(long int average[],int sort[],int n){
	int i,g,front,front1;
	for(i=0;i<=n-1;i++) sort[i]=i;
	
	for(g=1;g<=n-1;g++){
		for(i=1,front=average[0],front1=sort[0];i<=n-1;i++){
			if(average[i]<front){
				average[i-1]=average[i];
				average[i]=front;
				
				sort[i-1]=sort[i];
				sort[i]=front1;
			} 
			front=average[i];
			front1=sort[i];	
		}
	} 
}
void outputarray(long int array[][100],int n,int sort[]){
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			printf("%d",array[sort[i]][j]);
			if(j!=n-1) printf(" ");
			else printf("\n");
		}
	}
}
int main()
{
	long int array[100][100],average[100];
	int sort[100],n;
	scanf("%d",&n);
	inputarray(array,n);
	findaverage(array,n,average);
	sortaverage(average,sort,n);
	outputarray(array,n,sort);
}

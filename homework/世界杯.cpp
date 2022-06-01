#include<stdio.h>
struct team{
	char name[21];
	int in;
	int lose;
	int score;
};
typedef struct team TEAM;
int Comp(TEAM *p1,TEAM *p2){
	if((p1->score)<(p2->score)) return 1;
	else if((p1->score)>(p2->score)) return 0;
	else if(((p1->in)-(p1->lose))<((p2->in)-(p2->lose))) return 1;
	else if(((p1->in)-(p1->lose))>((p2->in)-(p2->lose))) return 0;
	else if((p1->in)<(p2->in)) return 1;
	else return 0;
}
void Swap(TEAM *p1,TEAM *p2){
	TEAM temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}

void Sort(TEAM *teams,int n){
	int i,ovo,j;
	void Swap(TEAM *p1,TEAM *p2);
	int Comp(TEAM *p1,TEAM *p2);
	for(j=1;j<=n-1;j++)
		for(i=0;i<n-1;i++){
			ovo=Comp(teams+i,teams+i+1);
			if(ovo){
				Swap(teams+i,teams+i+1);
			}
		}
}
int main(){
	TEAM teams[4];
	int i;
	for(i=0;i<=3;i++){
		scanf("%s",teams[i].name);
		scanf("%d",&teams[i].in);
		scanf("%d",&teams[i].lose);
		scanf("%d",&teams[i].score);
	}
	Sort(teams,4);
	for(i=0;i<=3;i++){
		printf("%s\n",teams[i].name);
	}
}



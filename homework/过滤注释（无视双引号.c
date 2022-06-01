#include<stdio.h>
#define STATE_normal 10//正常状态 
#define STATE_0 0//遇到"    /     " 
#define STATE_1 1//遇到“   //    "
#define STATE_2 2//遇到“   /*    " 

#define STATE_5 5//遇到“   */    ” 
#define STATE_6 6//遇到“   /**   ” 
void removeNOTE(FILE *fp,int a,int b){
	int pass=0,state=STATE_normal,flag=1;
	char ch;
	ch=fgetc(fp);
	while(flag){
		if(ch=='/'&&state==STATE_normal) 	state=STATE_0;
		else if(ch=='/'&&state==STATE_0) 	state=STATE_1;//"  // "
		else if(ch=='*'&&state==STATE_0) 	state=STATE_2;//" /* "
		else if(ch=='*'&&state==STATE_2) 	state=STATE_6;//"  /** "
		else if(ch=='/'&&state==STATE_6) 	state=STATE_5;// /**/
		else if(ch!='/'&&ch!='*'&&state==STATE_6)	state=STATE_2;//" behind /** there are other chars.
		
		else if(ch!='/'&&ch!='*'&&state==STATE_0){
			state=STATE_normal;
			printf("/");
		}// only one '/' 
		
		if(state==STATE_1&&ch=='\n') 	state=STATE_normal;// the '//' notes end
		if(state==STATE_normal)	 putchar(ch);
		if(state==STATE_5) 	state=STATE_normal;// the '/**/'notes or '""' end
		if(ch=='\n') pass++;
		ch=fgetc(fp);
		if(pass==b-a) flag=0;
	}
}
int main()
{
	FILE *fptr=fopen("data1.txt","r");
	int location[6]={0},serial=0,i=0;
	char ch;
	if(fptr!=NULL){
		location[0]=5;
		for(i=0;i<=4;i++) {
			fscanf(fptr,"%d",&location[i+1]);	
		}//存取代码段位置 
		location[5]--;
		scanf("%d",&serial);
		while(i<=location[serial-1]){
			ch=fgetc(fptr);
			if(ch=='\n')	i++;
		}//跳过不需要测试的代码段 
		removeNOTE(fptr,location[serial-1],location[serial]);
		fclose(fptr);
	}
	else printf("error");
	
} 

#include<stdio.h>
#define STATE_normal 10//����״̬ 
#define STATE_0 0//����"    /     " 
#define STATE_1 1//������   //    "
#define STATE_2 2//������   /*    " 
#define STATE_3 3//������   ���������ţ�   �� 
#define STATE_4 4//������   ���������ţ�(�ٴ��������ţ�   �� 
#define STATE_5 5//������   */    �� 
#define STATE_6 6//������   /**   �� 
void removeNOTE(FILE *fp,int a,int b){
	int pass=0,state=STATE_normal,flag=1;
	char ch;
	ch=fgetc(fp);
	while(flag){
		if(ch=='"'&&state==STATE_normal) 	state=STATE_3;
		else if(ch=='"'&&state==STATE_3) 	state=STATE_4;
		else if(state!=STATE_3){
			if(ch=='/'&&state==STATE_normal) 	state=STATE_0;
			else if(ch=='*'&&state==STATE_0) 	state=STATE_2;//" /* "
			else if(ch=='/'&&state==STATE_0) 	state=STATE_1;//"  // "
			else if(ch=='*'&&state==STATE_2) 	state=STATE_6;//"  /** "
			else if(ch!='/'&&ch!='*'&&state==STATE_6)	state=STATE_2;//" behind /** there are other chars.
			else if(ch=='/'&&state==STATE_6) 	state=STATE_5;// /**/
			else if(ch!='/'&&ch!='*'&&state==STATE_0){
				state=STATE_normal;
				printf("/");
			}// only one '/' 
		}
		if(state==STATE_1&&ch=='\n') 	state=STATE_normal;// the '//' notes end
		if(state==STATE_normal||state==STATE_3||state==STATE_4)	 putchar(ch);
		if(state==STATE_5||state==STATE_4) 	state=STATE_normal;// the '/**/'notes or '""' end
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
		}

		scanf("%d",&serial);
		while(i<=location[serial-1]){
			ch=fgetc(fptr);
			if(ch=='\n')	i++;
		}
		removeNOTE(fptr,location[serial-1],location[serial]);
	}
	else printf("error");
	fclose(fptr);
} 

#include<stdio.h>
int main()
{
	FILE *fp=fopen("dict.dic","rb");
	char a,aa[6];
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int i,pass=0,SIZE=6*(sizeof(a)+sizeof(b)+sizeof(c)+sizeof(d)+sizeof(e)+sizeof(g)+sizeof(h));//计算一次输入数据的大小 
    if(fp==NULL) printf("I can't open the file.");
    else{
    	scanf("%d",&i);
    	fseek(fp,(i-1)*SIZE,1);
   		fread(&a,sizeof(a),1,fp);
  		fread(&b,sizeof(b),1,fp);
   		fread(&c,sizeof(c),1,fp);
   		fread(&d,sizeof(d),1,fp);
   		fread(&e,sizeof(e),1,fp);
   		fread(&g,sizeof(g),1,fp);
   		fread(&h,sizeof(h),1,fp);
   		fread(aa,sizeof(a),5,fp);
   		fread(bb,sizeof(b),5,fp);
    	fread(cc,sizeof(c),5,fp);
    	fread(dd,sizeof(d),5,fp);
    	fread(ee,sizeof(e),5,fp);
    	fread(gg,sizeof(g),5,fp);
    	fread(hh,sizeof(h),5,fp);
		 
    	printf("%c\n%hd\n%d\n%ld\n%lld\n%f\n%lf\n",a,b,c,d,e,g,h);
    	printf("%s\n",aa);
    	for(pass=0;pass<=4;pass++){
    		printf("%hd",bb[pass]);
    		if(pass<4) printf(" ");
		}
		printf("\n");
		for(pass=0;pass<=4;pass++){
    		printf("%d",cc[pass]);
    		if(pass<4) printf(" ");
		}
		printf("\n");
		for(pass=0;pass<=4;pass++){
    		printf("%ld",dd[pass]);
    		if(pass<4) printf(" ");
		}
		printf("\n");
		for(pass=0;pass<=4;pass++){
    		printf("%lld",ee[pass]);
    		if(pass<4) printf(" ");
		}
		printf("\n");
		for(pass=0;pass<=4;pass++){
    		printf("%f",gg[pass]);
    		if(pass<4) printf(" ");
		}
		printf("\n");
		for(pass=0;pass<=4;pass++){
    		printf("%lf",hh[pass]);
    		if(pass<4) printf(" ");
		}
	}
	fclose(fp);
} 

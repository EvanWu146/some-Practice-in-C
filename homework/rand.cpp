#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i;
	srand(time(NULL));
	for(i=1;i<=20;i++)
	{
		printf("%2d",1+rand()%7);
		if(i%5==0)
			printf("\n");
	}
	printf("%lld",time(NULL));
	return 0;
 } 

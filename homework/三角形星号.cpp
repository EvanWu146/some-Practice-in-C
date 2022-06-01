#include<stdio.h>
main()
{
	int line;
	int count;
	int LINES;
	scanf("%d",&LINES);
	
	line=1;
	while(line<=LINES)
	{
		count=1;
		while(count<=line)
		{
			printf("*");
			count++;
		}
		printf("\n");
		line++;
	}
	return 0;
	
}

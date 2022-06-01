#include <stdio.h>

int main()
{
	int a1,a2,a3,a4,a5;//num
	int o1,o2,o3,o4,o5;//operator
	int flag=0;//ans existed
	int T,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		flag=0;
		scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
		for(o1=-1;o1<=1;o1++)
		{
			for(o2=-1;o2<=1;o2++)
			{
				for(o3=-1;o3<=1;o3++)
				{
					for(o4=-1;o4<=1;o4++)
					{
						for(o5=-1;o5<=1;o5++)
						{
							if(o1*a1+o2*a2+o3*a3+o4*a4+o5*a5==24)
							{
								flag=1;
								//printf("%d %d %d %d %d",o1*a1,o2*a2,o3*a3,o4*a4,o5*a5);	
							}
						}
					}
				}
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}


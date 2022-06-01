#include <stdio.h>
 
int main()
{
    int i, j, n;
    scanf("%d", &n);
    
    for (i=0; i<n; i++) 
	{
        for (j=0; j<n-i-1; j++) { 
            printf(" ");
        }
        for (j=0; j<2*i+1; j++) {
            printf("*");
        }
        for (j=0; j<n-i-1; j++) { 
            printf(" ");
        }
        printf("\n"); 
    }
    for (i=1; i<n; i++) /*从i=1开始，打印n-1行*/
	{ 
        for (j=0; j<i; j++) { 
            printf(" ");
        }
        for (j=0; j<2*(n-i)-1; j++) { 
            printf("*");
        }
        for (j=0; j<i; j++) { 
            printf(" ");
        }
        printf("\n"); 
    }
    return 0;
}



#include <stdio.h>
int main()
{
    long long int a,b,c,m,t;
    scanf("%lld%lld",&a,&b);
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    m=a*b;
    c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    printf("%lld %lld",b,m/b);
}

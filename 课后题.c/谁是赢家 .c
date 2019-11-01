#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a=0,b=0;
    int i,t;
    for(i=0;i<3;i++)
    {
        scanf("%d",&t);
        if(t)b++;
        else a++;
    }
    if(a+m>b+n)printf("The winner is a: %d + %d",m,a);
    else if(a+m<b+n)printf("The winner is a: %d + %d",n,b);
}

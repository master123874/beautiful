#include<stdio.h>
int add(int m,int n)
{
    int result=0;
    while(n)
    {
        result+=n%10;
        n/=10;
    }
    if(m==result)return 1;
    return 0;
}
int judge(int n)
{
    int t=n;
    int result=0;
    while(t)
    {
        result=result*10+t%10;
        t/=10;
    }
    if(result==n)return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int flag=0;
    printf("%d\n",n);
    for(i=10000;i<=999999;i++)
    {
        if(judge(i)&&add(n,i))
        {
            printf("%d\n",i);
            flag=1;
        }
    }
    if(!flag)printf("-1");
}

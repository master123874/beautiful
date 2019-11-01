#include<stdio.h>
#define N 100
int main()
{
    long m,n;
    scanf("%ld %ld",&m,&n);
    int a=(n-m)/3600/N,b=(n-(a*3600*100))/60/N,c=(n-a*3600*100-b*60*100)/100;
    printf("%02ld:%ld:%ld",a,b,c);
}

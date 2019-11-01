#include<stdio.h>
int cowsum(int n)
{
    if(n==1)return 1;
    else if(n>=2&&n<=4)return cowsum(n-1)+1;
    else return cowsum(n-1)+cowsum(n-3);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        printf("%d\n",cowsum(n));
        scanf("%d",&n);
        if(n==0)break;
    }
}

#include<stdio.h>
#include<math.h>
int prime(int n);
int main()
{
    long int n;
    scanf("%d",&n);
    int count1=0,count2=0;
    int i;
    int a[20];
    for(i=2;i<=n;i++)
    {
        if(prime(i))
        {
            a[count1]=i;
            count1++;
        }
    }
    for(i=0;i<count1-1;i++)
    {
        if(a[i+1]-a[i]==2) count2++;
    }
    printf("%d",count2);
}
int prime(int n)
{
    int flag=1;
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag) return 1;
    return 0;
}

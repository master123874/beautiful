#include<stdio.h>
#include<math.h>
int prime(int n);
int main()
{
    int n;
    scanf("%d",&n);
    int count1=0L,count2=0L;
    int i;
    int a[1000]={0};
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
          return 0;
    }
    return 1;
}

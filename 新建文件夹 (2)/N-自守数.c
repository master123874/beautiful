#include<stdio.h>
#define N 10
int judge(int m)
{
    int i;
    for(i=10;;i*=10)
      if(i>m)return i;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int flag;
    int t1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&t1);
        flag=0;
        for(j=0;j<10;j++)
        {
            if((j*t1*t1)%judge(t1)==t1)
            {
                flag=1;
                printf("%d %d\n",j,j*t1*t1);
                break;
            }
        }
        if(!flag)printf("No\n");
    }

}

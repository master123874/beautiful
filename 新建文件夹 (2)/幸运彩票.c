#include<stdio.h>
#include<math.h>
#define N 7
int retusum(char t[N])
{
    int i,sum=0,sum1=0;
    int s[2]={2,2};
    for(i=0;i<6;i++)
    {
        if(i<3)
        {
            sum+=t[i]-'0';
            s[0]--;
        }
        else
        {
            sum1+=t[i]-'0';
            s[1]--;
        }
    }
    printf("%d",sum);
    if(sum==sum1)return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char t[N];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",t);
        if(retusum(t))printf("You are lucky!\n");
        else printf("Wish you good luck.\n");
    }

}

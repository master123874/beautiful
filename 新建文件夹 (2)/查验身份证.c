#include<stdio.h>
#include<string.h>
#define N 19
#define S 11
int main()
{
    char a[S]={'1','0','X','9','8','7','6','5','4','3','2'};
    int b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int n;
    scanf("%d",&n);
    int i,j;
    char c[n][N];
    int sum=0;
    for(i=0;i<n;i++)scanf("%s",c[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<17;j++)
        {
            sum+=b[j]*((int)c[j]-48);
        }
        if(c[i][17]==a[sum%11])
        {
            printf("%s",c[i]);
            sum=0;
        }

    }
}

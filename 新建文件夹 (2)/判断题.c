#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int i,j;
    int a[n],b[n];
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    int score,t;
    for(i=0;i<m;i++)
    {
        score=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&t);
            if(t==b[j])score+=a[j];
        }
        printf("%d\n",score);
    }
}

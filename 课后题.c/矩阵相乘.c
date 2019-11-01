#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    long long a[m][m];
    int i,j,k;
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        scanf("%lld",&a[i][j]);
    long long m1,n1;
    scanf("%lld%lld",&m1,&n1);
    long long b[m1][n1];
    for(i=0;i<m1;i++)
      for(j=0;j<n1;j++)
        scanf("%lld",&b[i][j]);
    long long c[m][n1];
    for(i=0;i<m;i++)
      for(j=0;j<n1;j++)
        c[i][j]=0;
    for(i=0;i<m;i++)
      for(j=0;j<n1;j++)
        for(k=0;k<n;k++)
            c[i][j]+=a[i][k]*b[k][j];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("%lld",c[i][j]);
            if(j<n1-1) printf(" ");
        }
        printf("\n");
    }  
}

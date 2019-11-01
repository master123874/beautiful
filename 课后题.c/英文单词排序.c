#include<stdio.h>
int main()
{
    int a,b,c,d;
    int i,j;
    scanf("%d%d",&a,&b);
    int e[a][b];
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
          scanf("%d",&e[i][j]);
    scanf("%d%d",&c,&d);
    int f[c][d];
    int z[a][d];
    for(i=0;i<a;i++)
      for(j=0;j<d;j++)
        z[i][j]=0;
    int k;
    for(i=0;i<c;i++)
      for(j=0;j<d;j++)
        scanf("%d",&f[i][j]);
    if(b!=c)
    {
        printf("Error:%d !=%d",b,c);
        return 0;
    }
    else
    {
        for(i=0;i<a;i++)
          for(j=0;j<d;j++)
            for(k=0;k<b;k++)
             z[i][j]+=e[i][k]*f[k][j];
        printf("%d %d\n",a,d);     
        for(i=0;i<a;i++)
        {
            for(j=0;j<d;j++)
            {
                printf("%d ",z[i][j]);
            }
            printf("\n");
        }
                
    }

    

}

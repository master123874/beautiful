#include<stdio.h>
int main()
{
    int a,b;
    int i,j;
    scanf("%d %d",&a,&b);
    int c[a][b];
    for(i=0;i<a;i++)
      for(j=0;j<b;j++)
        scanf("%d",&c[i][j]);
    int d,e;    
    scanf("%d %d",&d,&e);
    int f[d][e];
    int k,g[a][e];
    for(i=0;i<a;i++)
      for(j=0;j<e;j++)
        g[i][j]=0;
    for(i=0;i<d;i++)
      for(j=0;j<e;j++)
        scanf("%d",&f[i][j]);
    if(b!=d)printf("Error: %d != %d",b,d);
    else
    {
        for(i=0;i<a;i++)
          for(j=0;j<e;j++)
            for(k=0;k<b;k++)
              g[i][j]+=c[i][k]*f[k][j];
        printf("%d %d\n",a,e);
        for(i=0;i<a;i++)
        {
            for(j=0;j<e;j++)
            {
                printf("%d",g[i][j]);
                if(j<e-1)printf(" ");
            }
            printf("\n");
        }   

    }        
}

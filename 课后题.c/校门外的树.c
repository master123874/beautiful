#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int i;
    int a[m];
    int count=m+1;
    int b[n],c[n];
    for(i=0;i<=m;i++)
       a[i]=1;
    getchar();  
    int j,i1; 
    for(i=0;i<n;i++)
      scanf("%d%d",&b[i],&c[i]);
    for(i=0;i<n;i++)
    {
        for(j=b[i];j<=c[i];j++)
        {
            if(a[j])a[j]=0;
        }   
    }
    for(i=0;i<=m;i++)
    {
        if(!a[i]) count--;
    }
    printf("%d",count);
         
}

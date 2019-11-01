#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    int m,t,d;
    scanf("%d",&m);
    for(i=0;i<n-1;i++)
    {
        if(m>a[i]&&m<a[i+1]) 
        {
            t=i+1;
            break;  
        }  
    }
    for(i=t;i<n;i++)
    {
        b[i]=a[i];
    }
    n++;
    for(i=t;i<n;i++)
    {  
        a[i+1]=b[i]; 
    }
    a[t]=m;
    for(i=0;i<n;i++)
      printf("%d ",a[i]);
}

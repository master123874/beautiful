#include<stdio.h>
#include<math.h>
int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
      scanf("%d",&a[i]);
    int min=abs(a[0]);
    int t=0;
    for(i=1;i<10;i++)
    {
        if(abs(a[i])<min)
          t=i;
    }
    int temp;
    temp=a[t];
    a[t]=a[9];
    a[9]=temp;
    for(i=0;i<10;i++)
     printf("%d ",a[i]);
}

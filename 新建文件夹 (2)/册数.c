#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][2];
    int i,j;
    for(i=0;i<n;i++)
      for(j = 0;j < 2;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        if(fabs(a[i][1]-2*(a[i][0]-100)*0.9)<(a[i][0]-100)*0.9*0.1*2)printf("You are wan mei!\n");
        else if(a[i][1]>2*(a[i][0]-100)*0.9)printf("You are tai pang le!\n");
        else if(a[i][1]<2*(a[i][0]-100)*0.9)printf("You are tai shou le!\n");
    }    
}

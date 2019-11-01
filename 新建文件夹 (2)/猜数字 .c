#include<stdio.h>
#include<math.h>
typedef struct s{
    char a[9];
    int num;
}S;
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    S p[n];
    for(i=0;i<n;i++)
      scanf("%s %d",p[i].a,&p[i].num);
    int sum=0;
    for(i=0;i<n;i++)
      sum+=p[i].num;
    int t=0;  
    int min=abs(p[0].num-sum/n/2);
    for(i=1;i<n;i++)
      if(abs(p[i].num-sum/n/2)<min)
      {
          min=abs(p[i].num-sum/n/2);
          t=i;
      }
    printf("%d %s",sum/n/2,p[t].a);
    
}

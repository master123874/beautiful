#include<stdio.h>
#include<string.h>
#define N 17
typedef struct s{
    char a[N];
    int b,c;
}S;
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    S p[n];
    for(i = 0;i < n;i ++)
      scanf("%s %d %d",p[i].a,&p[i].b,&p[i].c);
    int m;
    scanf("%d",&m);
    int e[m],j;
    for(i = 0;i < m;i ++)
      scanf("%d",&e[i]);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
           if(p[j].b==e[i])
           {
               printf("%s %d\n",p[j].a,p[j].c);
               break;
           }
    }  



}

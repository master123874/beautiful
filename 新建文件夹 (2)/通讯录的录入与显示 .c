#include<stdio.h>
#include<stdlib.h>
typedef struct s{
    char a[11];
    char sex;
    int year,month,day;
    char b[16],c[16];
}S;
int main()
{
    int n;
    scanf("%d",&n);
    S p[n];
    int i;
    for(i=0;i<n;i++)scanf("%s %s %s %c %d/%d/%d",p[i].a,p[i].b,p[i].c,&p[i].sex,&p[i].year,&p[i].month,&p[i].day);
    int m;
    scanf("%d",&m);
    int e[m];
    for(i=0;i<m;i++)
      scanf("%d",&e[i]);
    for(i=0;i<m;i++)
    {
        if(e[i]>n-1)printf("Not Found\n");
        else printf("%s %s %s %c %d/%d/%d\n",p[e[i]].a,p[e[i]].b,p[e[i]].c,p[e[i]].sex,p[e[i]].year,p[e[i]].month,p[e[i]].day);
    }  

}

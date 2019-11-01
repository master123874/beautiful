#include<stdio.h>
#include<stdlib.h>
struct s
{
    double change;
    double zhong;
    double single_change;
}t[1001];
void sort(struct s t[],int m);
int getmax(int n,struct s t[],int m);
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int i;
    for(i=0;i<m;i++)
        scanf("%lf",&t[i].zhong);
    for(i=0;i<m;i++)
        scanf("%lf",&t[i].change);
    for(i=0;i<m;i++)
        t[i].single_change=t[i].change/t[i].zhong;
    sort(t,m);
    printf("出售价格最高为%.2lf.",getmax(n,t,m));

}
void sort(struct s t[],int m)
{
    int i,j;
    struct s t1;
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(t[j].single_change>t[i].single_change)
            {
                t1=t[i];
                t[i]=t[j];
                t[j]=t1;
            }

        }
    }
}
int getmax(int n,struct s t[],int m)
{
    double salary=0;
    int i;
    for(i=0;i<m;i++)
    {
        if(t[i].zhong>=n)
        {
            salary=t[i].single_change*n;
            return salary;
        }
        else
        {
            salary+=t[i].change;
            n-=t[i].zhong;
        }
    }
}

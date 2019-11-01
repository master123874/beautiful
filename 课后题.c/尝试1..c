#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int split(int n,int t[]);
int getmaxn(int t[]);
void sort(int t[]);
void sortr(int t[]);
int getminn(int t[]);
int output(int t[]);
const int i=4;
int main()
{
    int n,count=0;
    int t[4]={0,0,0,0};
    scanf("%d",&n);
    split(n,t);
    output(t);
    return 0;
}
int split(int n,int t[])
{
    int i1=0,j=0;
    for(;j<i;j++)
       t[j]=0;
    while(n>0)
    {
        t[i1]=n%10;
        i1++;
        n/=10;
    }
}
void sortr(int t[])
{
    int j,k,t1;
    for(j=0;j<i;j++)
    {
        for(k=j+1;k<i;k++)
        {
            if(t[k]<t[j])
            {
                t1=t[j];
                t[j]=t[k];
                t[k]=t1;
            }
        }
    }
}
void sort(int t[])
{
    int j,k,t1;
    for(j=0;j<i;j++)
    {
        for(k=j+1;k<i;k++)
        {
            if(t[k]>t[j])
            {
                t1=t[j];
                t[j]=t[k];
                t[k]=t1;
            }
        }
    }
}
int getmaxn(int t[])
{
    int j,k=i,max=0;
    sort(t);
    for(j=0;j<i;j++)
    {
        max+=t[j]*pow(10,--k);
    }
    return max;
}
int getminn(int t[])
{
    int j,k=i,min=0;
    sortr(t);
    for(j=0;j<i;j++)
    {
        min+=t[j]*pow(10,--k);
    }
    return min;
}
int output(int t[])
{
    const int nchange=6174;
    int t1,t2;
    int count=0;
    if(getmaxn(t)==getminn(t))
    {
        printf("%.4d - %.4d = 0000\n",getmaxn(t),getminn(t));
        return 0;
    }
    while(1)
    {
        t1=getmaxn(t);
        t2=getminn(t);
        if(t1-t2==nchange)
        {
            printf("%.4d - %.4d = 6174\n",t1,t2);
            return 0;
        }
        else
        {
            printf("%.4d - %.4d = %.4d\n",t1,t2,t1-t2);
        }
        split(t1-t2,t);
    }

}

#include<stdio.h>
void s_d(long n,float s,float t,float sn,long h);
void main()
{
    long h,n;
    scanf("%ld%ld",&h,&n);
    float s=0,sn=(float)h,t=(float)h;
    s_d(n,s,t,sn,h);
}
s_d(long n,float s,float t,float sn,long h)
{
    int a=1;
    for(;a<=n;a++)
    {
        s+=sn;
        t/=2;
        sn=2*t;
    }
    if(n==0)printf("%.1f 0.0\n",(float)h);
    else printf("%.1f %.1f\n",s,t);
}


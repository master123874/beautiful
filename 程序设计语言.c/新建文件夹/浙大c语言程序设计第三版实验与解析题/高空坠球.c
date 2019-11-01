#include<stdio.h>
void s_d(double n,double s,double sn,double h);
int main()
{
    double n;
    double h;
    scanf("%lf %lf",&h,&n);
    double s=0,sn=h;
    s_d(n,s,sn,h);
    return 0;
}
void s_d(double n,double s,double sn,double h)
{
    int a=1;
    for(;a<=n&&n>0&&h>=0;a++)
    {
        s+=sn;
        h/=2;
        sn=2*h;
    }
    if(n==0)printf("%.1lf 0.0\n",s);
    else printf("%.1lf %.1lf\n",s,h);
}

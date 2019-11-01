#include<stdio.h>
int main()
{
    int a=1;
    long int h,n;
    scanf("%ld%ld",&h,&n);
    double s=0,sn=(double)h,t=double(h);
    while(a<=n&&h>0)
    {
        s+=sn;
        t/=2;
        sn=2*t;
        a++;
    }
    printf("%.1lf %.1lf\n",s,t);

}

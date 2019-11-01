#include<stdio.h>
int main()
{
    double  x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    double t=(y2-y1)/(x2-x1);
    double t2=(y4-y3)/(x4-x3);
    double x=(y3-y1-t2*x3+t*x1)/(t-t2);
    double y=t*x-t*x1+y1;
    if((y2-y1)/(x2-x1)==(y4-y3)/(x4-x3))printf("The two lines are parallel");
    else if(x2!=x1&&x4!=x3)printf("The intersecting point is at (%.15lf,%.15lf)",x,y);
}

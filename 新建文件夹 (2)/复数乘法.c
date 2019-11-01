#include<stdio.h>
#include<math.h>
void print(float image,float real)
{	
    if(image<0)printf("%.2f-%.2fi",real,fabs(image));
    else printf("%.2f+%.2fi",real,image);
}
int main()
{
    float a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    float real=a*cos(b)*c*cos(d)-a*sin(b)*c*sin(d);
    float image=a*cos(b)*c*sin(d)+c*cos(d)*a*sin(b);
    print(image,real);
}

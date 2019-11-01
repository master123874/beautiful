#include<stdio.h>
int main()
{
  int a,b,c,d,e;
  scanf("%d%d",&a,&b);
  if(b>0)
  {
  	c=b/60;
    e=a/100+c;
    b=b-60;
    d=b+(a-(a/100)*100);
    if(d>=60)e+=1;
    d-=60;
    a=e*100+d;
    printf("%4d",a);
  }
  else
  {
  	c=b/60;
    e=a/100+c;
    b=b+60;
    d=(a-(a/100)*100)+b;
    if(d<=0)e-=1;
    d=-d;
    a=e*100+d;
    printf("%4d",a);
  }
}

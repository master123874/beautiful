#include<stdio.h>
int main()
{
  float a,b,c,d;
  scanf("%f%f%f%f",&a,&b,&c,&d);
  if(d<a) printf("BW-Solid");
  else if(d>a)printf("R-Hollow");
  else if(d==a)printf("R-Cross");
  
  if(c<a&&c<d&&b>a&&b>d)printf(" with Lower Shadow and Upper Shadow");
  else if(c<a&&c<d)printf(" with Lower Shadow");
  else if(b>a&&b>d)printf(" with Upper Shadow");
  return 0;
}


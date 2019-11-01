#include<stdio.h>
int main()
{
  long a;
  int s=0;
  while(scanf("%ld",&a)==1)
  {
      while(a>0)
      {
          s+=a%10;
          a/=10;
      }
      printf("%d",s);
      s=0;
  }
}

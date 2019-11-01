#include<stdio.h>
int main()
{
  int lower,upper;
  float i;
  scanf("%d%d",&lower,&upper);
  
  if(lower<=upper)
  
  {
  	printf("fahr celsius\n");
    for(i=lower;i<=upper;i+=2)
    {
      printf("%-4.f %-7.1f\n",i,5*(i-32)/9);
    }
  }
  else printf("Invalid.");
  
  return 0;
}

#include<stdio.h>
int main()
{
  int Sum=0,a,b,count=0;
  scanf("%d%d",&a,&b);
  if(-100<=a&&a<=b&&b<=100)
  {

    for(;a<=b;a++)
    {
      Sum+=a;
      if(a==b) printf("%5d\nSum = %d",a,Sum);
     
      else printf("%5d",a);
      count++;
      if(count%5==0)printf("\n");
      
    }
    
  
  }
  
  return 0;
}

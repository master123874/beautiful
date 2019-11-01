#include<stdio.h>
int main()
{
  int i,a,b,c,d[10],count=0,flag=0;
  scanf("%d%d",&a,&b);
  c=a*b;
  while(c>0)
  {
    d[count++]=c%10;
    c=c/10;
    
  }
  for(i=0;i<count;i++)
  {
    if(d[i]!=0) flag=1;
    if(flag==1) printf("%d",d[i]);
  }
  
  return 0;
  
}

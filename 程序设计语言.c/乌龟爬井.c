#include<stdio.h>
int main()
{
  int n,N,U,D,S=0;
  n=0;
  scanf("%d%d%d",&N,&U,&D);
  while(S<=N-1)
  {
    n++;
    S+=U-D;
    if(S>=N-1) break;
    else n++;
    
    
  }
  printf("%d",n);
  
  return 0;
  
}

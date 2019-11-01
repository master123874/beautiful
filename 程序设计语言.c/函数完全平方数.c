#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}
int IsTheNumber(const int N)
{
  int i=0,j,k,n,t;
  float a[10]={0},x;
  t=N;
  k=(int)(sqrt(N));
  if(k*k==N)
  {
    while(t>0)
    {
      a[i]=t%10;
      i++;
      t/=10;
    }
    x=a[0];
    for(j=1;j<=i-1;j++)
    {
    	if(x==a[j])
    	{
    		return 1;
    	
		}
		
		return 0;
    	
      
    }
    return 0;
    
  }
  
  
  
}

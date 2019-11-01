#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );
	
int main()
{
    int i, m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}
int factorsum( int number )
{
    int i;
    int s=0;
    if(number==1) return 1;
    for(i=1;i<number;i++)
    {
        if(number%i==0)s+=i;
    }
    return s;
}
void PrintPN( int m, int n )
{
    
    int i;
    int count=0;
    int j;
    for(i=m;i<=n;i++)
    {
    	if(i==1)
    	{
    		count++;
    		printf("%d = 1\n",i);
    		continue;
    	}
        if(factorsum(i) == i)
        {
        	printf("%d = 1",i);
        	count++;
            for(j=2;j<i;j++)
            {
            	if(i%j==0)
                  printf(" + %d",j);
            } 
			printf("\n");    
        }
    }
    if(!count)printf("No perfect number");
}

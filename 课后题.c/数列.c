#include <stdio.h>
int fib( int n );
void PrintFN( int m, int n );
	
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
int fib( int n )
{
    int i;
    int f1=1,f2=1;
    int f;
    if(n==1||n==2) return 1;
    for(i=3;i<=n;i++)
    {
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    return f;
}
void PrintFN( int m, int n )
{
	int i=1,j;
	int count=0;
    int b[10];
    for(j=1;fib(j)<=n;j++)
    {
    	if(fib(j)>=m&&fib(j)<=n)
    	{
    		if(i==0)
    		{
    			printf(" ");
    			printf("%d",fib(j));
			}
			else
			{
				printf("%d",fib(j));
				i=0;
				count++;
			}
		}
    	
	}
	if(!count)printf("No Fibonacci number");
	
}

#include <stdio.h>

int is(int number );
void count_sum( int a, int b );

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    if (is(a)) printf("%d is counted.\n", a);
    if (is(b)) printf("%d is counted.\n", b);
    count_sum(a, b);

    return 0;
}
int is(int number)
{
	int count=0,t;
	while(number!=0)
	{
		t=number%10;
		count+=t;
		number/=10;
	}
	
	if(count==5) return 1;
	else return 0;
} 
void count_sum(int a,int b)
{
	int i,count=0;
	double sum=0;
	for(i=a;i<=b;i++)
	{
		if(is(i))
		{
			sum+=i;
			count++;
	    }  
	}
	printf("count = %d,sum = %.lf",count,sum);
} 

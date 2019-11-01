#include<stdio.h>
int main()
{
	long n;
	long j=1;
	int count=0;
	scanf("%ld",&n);
	while(1)
	{
		count++;
		if(j%n==0)
		{
			printf("%ld %d %ld",j/n,count,j);
			return 0;
		}
		else j=j*10+1;
	}
}

#include<stdio.h>
long getmax(long long m,long long n)
{
	long long c;
	if(m>n)
	{
		long long t=m;
		m=n;
		n=t;
	}
	while(m)
	{
		c=n;
		n=m;
		m=c%n;
	}
	return n;
}
int main()
{
	long long m,n;
	register int i;
	int t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld",&m,&n);
		printf("%lld\n",getmax(m,n));
	}
}

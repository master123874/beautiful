#include<stdio.h>
static int flag1=0;
int max;
void retu(long m,long n,long p,long *a)
{
	int count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<m)continue;
		else if(a[i]<=m*p)count++;
	}
	if(!flag1)
	{
		max=count;
		flag1=1;
	}
	else
	{
		if(max<count)max=count;
	}		
}
int main()
{
	long n,p;
	scanf("%ld %ld",&n,&p);
	int i;
	long a[n],m;
	int flag=0;
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	for(i=0;i<n;i++)
	{
		retu(a[i],n,p,a);
	}
	printf("%d",max);
	  
}

#include<stdio.h>
#define N 10000
int main()
{
	int a[N],count=0,n,i,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum=(i+1)/2+(i+1)/3+(i+1)/5;
		a[i]=sum;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=a[i+1]) count++;
		
	}
	printf("%d",count);
}

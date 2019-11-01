#include<stdio.h>
#define N 10000
int main()
{
	int a[N],count=1,n,i,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum=(i+1)/2+(i+1)/3+(i+1)/5;
		a[i]=sum;
	}
	for(i=n-1;i>0;i--)
	{
		if(a[i]!=a[i-1]) count++;
		
	}
	printf("%d",count);
}

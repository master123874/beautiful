#include<stdio.h>
#define N 51
int main()
{
	int a[N]={0};
	int n;
	scanf("%d",&n);
	int i,t;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[t]++;
	}
	for(i=0;i<N;i++)
	{
		if(a[i])printf("%d:%d\n",i,a[i]);
	}
} 

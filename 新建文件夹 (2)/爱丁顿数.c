#include<stdio.h>
#define N 100000
int main()
{
	int n;
	int a[N];
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=n;i>=1;i--)
	{
		int count=0;
		for(j=0;j<n;j++)
			if(a[j]>i)count++;
		if(count>=i)
		{
			printf("%d",i);
			return 0;	
		}	
	}
	printf("0");
}

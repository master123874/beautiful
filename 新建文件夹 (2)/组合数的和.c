#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)continue;
			else
			{
				sum+=a[i]*10+a[j];
			}
		}
	}
	printf("%d",sum);
	
}

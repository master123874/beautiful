#include<stdio.h>
int main()
{
	int i,j,s=1,sum=0;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=1;j<=i+1;j++)s*=j;
		sum+=s;
		s=1;
	}
	printf("%d",sum);
}

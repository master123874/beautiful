#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int m,n;
		scanf("%d %d",&n,&m);
		if(m>=n/2)
		{
			int j;
			int sum=0;
			for(j=1;j<=n-1;j++)sum+=j;
			printf("%d",sum);
		}
		else
		{
			int j;
			int sum=0;
			for(j=1;j<=m;j++)sum+=n-j;
			for(j=m+1;j<=n-m;j++)sum+=m;
			for(j=1;j<m;j++)sum+=j;
			printf("%d",sum);
		}
		if(i<t-1)printf("\n");
		
	}
}

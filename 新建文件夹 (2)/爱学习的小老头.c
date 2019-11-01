#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i;
	int count=0;
	for(i=0;i<m;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			int t,t1;
			scanf("%d %d",&t,&t1);
			if(t||t1)count++;
		}
	} 
	printf("%d",count);
}

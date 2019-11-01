#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int t1;
		scanf("%d",&t1);
		int j;
		long count=0;  /*¼ÇÂ¼ÄÜÁ¿*/ 
		long sum=0;
		for(j=1;j<=t1;j++)
		{
			sum=sum+j;
			count+=sum*j;
		}
		printf("%ld\n",count%1000000007);
	}
}

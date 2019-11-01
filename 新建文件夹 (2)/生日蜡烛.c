#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	register int i,j;
	int m;
	scanf("%d",&m);
	int result=0;
	for(i=1;i<=m;i++)
	{
		for(j=i;j<=m;j++)
		{
			result+=j;
			if(result>=m)break;
		}
		if(result==m)
		{
			printf("%d %d",i,j);
			return 0;
		}
		result=0;
	}
}

#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int t=n/2+1;
	for(i=1;i<=n;i++)
	{
		int j;
		for(j=0;j<abs(t-i);j++)printf(" ");
		for(j=0;j<(t-abs(t-i))*2-1;j++)printf("*");
		printf("\n");
	}
}

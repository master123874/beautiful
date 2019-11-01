#include<stdio.h>
#include<stdlib.h>
int main()
{
	int spare;
	int n;
	int count=0;   
	scanf("%d",&n);
	while(n)
	{
		spare=n;
		while(spare>=2)
		{
			count+=spare/3;
			spare-=(spare/3)*2;
			if(spare==2)
			{
				count++;
				break;
			}
		}
		printf("%d\n",count);
		count=0;
		scanf("%d",&n);
	}
}

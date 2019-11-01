#include<stdio.h>
int main()
{
	int spare,n,t;
	int sum=n;
	spare=n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<=0)return 0;
		spare=n;
		int count=0,flag=0;
		while(spare>=2)
		{
			if(spare==2)
			{
				flag=1;
				printf("%d\n",count+1);
				break;
			}
			else
			{
				count+=spare/3;
				spare=spare-spare/3*2;
			}
		}
		if(!flag)printf("%d\n",count);
	}
}

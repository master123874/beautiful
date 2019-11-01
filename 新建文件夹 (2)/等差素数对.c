#include<stdio.h>
#include<stdlib.h>
#define N 1000
int judge(int n)
{
	int i;
	if(n<2)return 0;
	for(i=2;i<n;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}
int main()
{
	int i,j;
	int count;
	for(i=1;i<N;i++)
	{
		count=0;
		if(judge(i+1))
		{
			for(j=i+1;j<=10000;j+=i)
			{
				if(judge(j))count++;
			}
			if(count==10)
			{
				printf("%d",i);
				return 0;
			}
		}	
	}
}


#include<stdio.h>
#define N 10
int main()
{
	int i,j;
	int t,t1=0;
	int count=0,flag=1;
	for(i=0;i<N;i++)
	{
		scanf("%d",&t);
		if(i>=1&&t>0&&flag)
		{
			printf("%d",i);
			for(j=0;j<t1;j++)
			  printf("%d",0);
			for(j=0;j<t-1;j++)
			  printf("%d",i); 
			flag=0;   
		}
		else if(i>=1&&t>0)
		{
			for(j=0;j<t;j++)
			  printf("%d",i);
		}
		else if(i==0)t1=t;
		if(i>0&&t==0)count++;
	}
	if(count==N-1)printf("0");
} 

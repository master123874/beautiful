#include<stdio.h>
int main()
{
	int n;
	int t,t1;  /*记录酒量*/ 
	scanf("%d %d",&t,&t1);
	int i;
	scanf("%d",&n); /*划拳组数*/ 
	int s; /*记录数据*/ 
	char s1;
	int flag=0;
	int count=0,count1=0;
	for(i=0;i<n;i++)
	{
		int a[4];
		int j;
		for(j=0;j<4;j++)scanf("%d",&a[j]);
		if(a[0]+a[2]==a[1]&&a[0]+a[2]!=a[3])count++;
		else if(a[0]+a[2]==a[3]&&a[0]+a[2]!=a[1])count1++;
		if(count>t)
		{
			printf("A\n%d",count1);
			return 0;
		}
		if(count1>t1)
		{
			printf("A\n%d",count);
			return 0;
		}
	}
}

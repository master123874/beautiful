#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	int i,j;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	int max,flag=0,flag1=0;
	for(i=0;i<n;i++)
	{
		int result=0;
		if(a[i]>=0)flag=1;
		for(j=i;j<n;j++)
		{
			result+=a[j];
			if(!flag1)
			{
				flag1=1;
				max=result;
			}
			else if(max<result)
			{
				max=result;
			}
		} 	  
	}
	if(!flag)printf("0");
	else printf("%d",max);
} 

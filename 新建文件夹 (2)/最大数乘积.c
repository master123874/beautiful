#include<stdio.h>

int main()
{
	int n;  /*多少组测试数据*/
	scanf("%d",&n);
	int i;    /*循环变量*/
	for(i=0;i<n;i++)
	{
		int m,t;    /*m保存多少个数t保存从多少个数中找最大值*/
		scanf("%d %d",&m,&t);	
		int a[m];   /*定义数组保存数字*/
		int j;
		int count=0;
		int max,flag=0;
		for(j=0;j<m;j++)scanf("%d",&a[j]);
		for(j=0;j<m;j++)
		{
			count=1;
			int result=a[j];
			if(count==t)
			{
				if(!flag)
				{
					max=result;
					flag=1;
				}
				else if(max<result)
					max=result;
				count=0;	
			}
			else
			{
				int t1=j+1;
				int t2=t1;
				int t3=result;
				int t4=1;
				for(;t1<m;t1++)
				{
					result*=a[t1];
					count++;
					if(count==t)
					{
						if(!flag)
						{
							max=result;
							flag=1;
						}
						else if(max<result)
							max=result;
						count=0;
					}
				}
				
			}
		}
		printf("%d",max);
		 
	} 
		
} 

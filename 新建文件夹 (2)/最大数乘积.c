#include<stdio.h>

int main()
{
	int n;  /*�������������*/
	scanf("%d",&n);
	int i;    /*ѭ������*/
	for(i=0;i<n;i++)
	{
		int m,t;    /*m������ٸ���t����Ӷ��ٸ����������ֵ*/
		scanf("%d %d",&m,&t);	
		int a[m];   /*�������鱣������*/
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

#include<stdio.h>
int main()
{
	int n;
	int t=0,t1=0;
	int flag[5]={0},s[5]={0};
	scanf("%d",&n);
	int i;
	int t3;
	int count=0;
	int f1=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t3);
		if(t3%5==0&&t3%2==0)
		{
			s[0]+=t3;
			flag[0]=1;
		}
		else if(t3%5==1)
		{
			if(!t)
			{
				s[1]+=t3;
				t=1;
			}
			else
			{
				t=0;
				s[1]-=t3;
			}
			flag[1]=1;
		}
		else if(t3%5==2)
		{
			s[2]++;
			flag[2]=1;
		}
		else if(t3%5==3)
		{
			flag[3]=1;
			s[3]+=t3;
			count++;
		}
		else if(t3%5==4)
		{
			flag[4]=1;
			if(!t1)
			{
				t1=1;
				s[4]=t3;
			}
			else
			{
				if(s[4]<t3)s[4]=t3;
			}
		}	
	}
	for(i=0;i<5;i++)
	{
		if(!f1&&!flag[i])
		{
			printf("N");
			f1=1;
		}
		else if(f1&&!flag[i])
		{
			printf(" N");
		}
		else if(!f1&&flag[i]&&i==3)
		{
			printf("%.1f",(float)s[i]/count);
			f1=1;
			continue;
		}
		else if(f1&&flag[i]&&i==3)
		{
			printf(" %.1f",(float)s[i]/count);
			continue;
		}
		else if(!f1&&flag[i])
		{
			printf("%d",s[i]);
			f1=1;
		}
		else if(f1&&flag[i])printf(" %d",s[i]);
	}
}

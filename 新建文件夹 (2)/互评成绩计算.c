#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j,t,count;
	int max,min,flag,t1,s;
	for(i=0;i<n;i++)
	{
		flag=0;
		s=0;
		count=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&t);
			if(t<0||t>m)
			{
				
				count++;
				continue;
			}
			if(!flag)
			{
				if(j==0)t1=t;
				else
				{
					max=t;
					min=t;
					s+=t;
					flag=1;
				}
			}
			else
			{
				s+=t;
				if(max<t)max=t;
				if(min>t)min=t;
			}
		}
		if((t1+(s-max-min)/(n-count-3))%2==0)
		  printf("%d\n",(t1+(s-max-min)/(n-count-3))/2);
		else printf("%d\n",(t1+1+(s-max-min)/(n-count-3))/2);  
	}
}

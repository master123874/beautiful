#include<stdio.h>
int judge(int m,int n)
{
	int i;
	while(n!=1)
	{
		if(n%2==0)
		{
			n/=2;
			if(m==n)return 1;
		}
		else
		{
			n=(3*n+1)/2;
			if(m==n)return 1;
		}
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a[n];
	int t[n],count=0;
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	int x;  
	
	for(i=0;i<n;i++)
	{
		x=0;
		if(a[i]==1)
		{
			t[count]=a[i];
			count++;
		}
		else
		{
			for(j=0;j<n;j++)
			{
				if(i==j)continue;
				else
				{
					if(!judge(a[i],a[j]))
					  x++;
					else break;	
				}
			}
			if(x==n-1)
			{
				t[count]=a[i];
				count++;
			}
		}
	} 
	int t1,change=1;
	for(i=0;i<count&&change;i++)
	{
		change=0;
		for(j=0;j<count-i-1;j++)
		{
			if(t[j]<t[j+1])
			{
				t1=t[j];
				t[j]=t[j+1];
				t[j+1]=t1;
				change=1;
			}
		}
	}
	for(i=0;i<count;i++)
	{
		printf("%d",t[i]);
		if(i<count-1)printf(" ");
	}
	  
	
}
 

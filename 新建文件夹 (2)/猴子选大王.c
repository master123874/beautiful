#include<stdio.h>
int judge(int a[],int b[],int m,int n)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(a[n-m+i]!=b[i])return 0;
	}
	return 1;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,k;
	int t1[n],t2[m];
	for(i=0;i<m;i++)scanf("%d",&t2[i]);
	int t=0,s,z=n; 
	int flag=0;
	int a[n];
	for(k=1;k<=n;k++)
	{
		z=n;
		int count=0;
		for(i=0;i<n;i++)a[i]=i+1;
		while(z>=1)
		{
			for(i=0;i<n;i++)
			{
				if(a[i])
				{
					t++;
					if(t==k)
					{
						t1[count]=a[i];
						count++;
						a[i]=0;
						t=0;
						z--;
					}
				}
			}
		}
		if(judge(t1,t2,m,n))
		{
			printf("%d",k);
			return 0;
		}
		
	}
	printf("0");
} 

#include<stdio.h>
void sort(int *a,int n)
{
	int i,j,change=1;
	for(i=0;i<n&&change;i++)
	{
		change=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				change=1;
			}
		}
	}	
} 
int judge(int i,int t,int *a,int n,int m)
{
	for(;i<m;i++)
	  if(a[i]+t==n)return 1;
	return 0; 
}
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int a[m];
		int i,j;
		int smallest;
		int flag=0;
		for(i=0;i<m;i++)scanf("%d",&a[i]);
		sort(a,m);
		for(i=0;i<m-1;i++)
		{
			if(judge(i+1,a[i],a,n,m))
			{
				flag=1;
				printf("%d %d\n",a[i],n-a[i]);
				break;
			}
		}
		if(!flag)printf("No Solution\n");
	}
}

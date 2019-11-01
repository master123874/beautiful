#include<stdio.h>
#include<stdlib.h>
int t5=0;
int getlucky(int *a,int n)
{
	int i;
	for(i=t5;i<n;i++)
	{
		if(!i)return 1;
		if(a[i])return a[i];
	}
	return 0;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int *a=(int *)malloc(sizeof(int)*n);
	int i,j;
	int count=0;
	int t=2;
	int lucky=1;
	for(i=0;i<n;i++)a[i]=i+1;
	for(i=0;i<n;i++)
	{
		int t1=0;
		lucky=a[i];
		t=lucky;
		if(!i)t=2;
		for(j=0;j<n;j++)
		{
			if(a[j])
			{
				t1++;
				if(t1%t==0)
				{
					a[j]=0;
				}
			}
		}
		t5++;
	}
	printf("%d",count);	
} 

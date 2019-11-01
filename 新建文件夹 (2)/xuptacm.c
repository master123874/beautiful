#include<stdio.h>
#include<string.h>
#define N 1000
void sort(int a[],int n)
{
	int i,j;
	int change=1;
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
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		int i;
		int a[t];
		for(i=0;i<t;i++)scanf("%d",&a[i]);
		sort(a,t);
		for(i=0;i<t;i++)printf("%6d",a[i]);
		printf("\n");
	}
	
}

#include<stdio.h>
static int count=0;
void insertsort(int *a,int n)
{
	int i;
	int j;
	for(i=1;i<n;i++)
	{
		int t=a[i];
		j=i-1;
		while(j>=0&&t>a[j])
		{
			a[j+1]=a[j--];
		}
		a[j+1]=t;
	}
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)printf("%d ",a[i]);
}
void process(int *a,int n)
{
	int i;
	int t=0;
	for(i=0;i<n;i++)t+=a[i];
	count=t;
	if(n>3)
	{
		for(i=0;i<n-2;i+=2)
		{
			int t1=a[i]+a[i+1];
			count+=(t-t1);
			count+=t1;
			t=t-t1;
		}
	}
	else if(n==3)count+=(a[1]+a[2]);
	else if(n==1)
	{
		printf("0");
		return;
	}
	printf("%d",count);
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	insertsort(a,n);
	process(a,n);
}

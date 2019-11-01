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
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,n);
	float t=a[0];
	for(i=1;i<n;i++)
	{
		t+=a[i];
		t/=2;
	}
	printf("%d",(int)t);
}

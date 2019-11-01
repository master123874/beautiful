#include<stdio.h>
void sort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int retusum(int a[],int n)
{
	int i;
	int s=0,s1=0;
	for(i=0;i<n;i++)
	{
		if(i<n/2)s+=a[i];
		else s1+=a[i];
	}
	return s1-s;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	if(n<=1)return 0;
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	sort(a,n);
	int diff=0;
	diff=retusum(a,n);
	int t=n/2;
	printf("Outgoing #: %d\n",n-t);
	printf("Introverted #: %d\n",t);
	printf("Diff = %d",diff);
} 

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,t;
	int a[n];
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	int max=a[0],min=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max) max=a[i];
		else if(a[i]<min) min=a[i];			
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==min)
		{
			t=a[0];
			a[0]=a[i];
			a[i]=t;
		}
		if(a[i]==max)
		{
			t=a[n-1];
			a[n-1]=a[i];
			a[i]=t;
		}
    } 
	for(i=0;i<n;i++)
	  printf("%d ",a[i]); 
	
} 

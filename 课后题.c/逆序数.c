#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	int count=0;
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	int j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			  count++;
		}
	}
	printf("%d",count);  
} 

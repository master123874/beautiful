#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int a[m];
	int i,j,t;
	for(i=0;i<m;i++)
	  scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<m;i++)
	   printf("%d ",a[i]);
} 

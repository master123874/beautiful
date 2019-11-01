#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n;
	scanf("%d",&m);
	long a[m+1];
	int i;
	for(i=1;i<=m;i++)
	  scanf("%ld",&a[i]);
	scanf("%d",&n);
	int b[n+1][2];
	int j;
	int max;
	int k;
	for(i=1;i<=n;i++)
	  for(j=0;j<2;j++)
	    scanf("%d",&b[i][j]);
	for(i=1;i<=n;i++)
	{
		j=b[i][0];
		max=a[j];
		for(k=j+1;k<=b[i][1];k++)
			if(a[k]>max)max=a[k];
		printf("%d\n",max);
	}    
  
} 

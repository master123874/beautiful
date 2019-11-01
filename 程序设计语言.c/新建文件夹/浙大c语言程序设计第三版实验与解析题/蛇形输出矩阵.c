#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j;
	int k=1,b=2,c=1,d=k,e=b;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("%d ",d);
			d+=e;
			e++;
		}
		printf("\n");
		k+=c;
		d=k;
		b++;
		e=b;
		c++;
	}
	
	return 0;
} 

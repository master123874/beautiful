#include<stdio.h>
#include<math.h>
int main() 
{
	int n;
	scanf("%d",&n);
	int i,j;
	long a[n];
	long s=0;
	for(i=0;i<n;i++)
	  scanf("%ld",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)s+=abs(a[i]-a[j]);  
		}
	}
	printf("%ld",s);
}

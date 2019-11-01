#include<stdio.h>
int main()
{
	int n;
	int a[1000];
	int i=0;
	scanf("%d",&n);
	while(n!=0)
	{
		a[i]=n%-2;
		n/=-2;
		i++;
	}
	int j;
	for(j=i-1;j>=0;j--)
	  printf("%d",a[j]);
}

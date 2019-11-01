#include<stdio.h>
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(k=2;k<=i;k++)
		  printf(" ");
		for(j=n-i+1;j>=1;j--)
		  printf("*");
		printf("\n");  
	}
	
	return 0;
} 

#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k,a,b;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		b=i%a;
		for(k=0;k<fabs(n/2-i);k++)
		  printf(" ");
		for(j=1;j<=2*i+1;j++)
		  printf("*");
		printf("\n");
	}
	
	return 0;
} 

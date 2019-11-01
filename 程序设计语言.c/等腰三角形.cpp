#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,k,L,M;
	for (i=1;i<=5;i++)
	{
		k=abs(3-i);
		L=pow(2,k);
		M=6-L;
		for (j=1;j<=L-1;j++)
		{
			printf(" ");
		}
		for (j=1;j<=M;j++)
		{
			printf("*");
		}
		printf("\n"); 
	}
	
	return 0;
}


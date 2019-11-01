#include<stdio.h>
#include<math.h>
#define N 9
int main()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<=i;j++)
		  printf("*");
		printf("\n");  
	}
	
}

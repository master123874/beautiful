#include<stdio.h>
int main()
{
	int i,k,g,j=5;
	char ch=' ',c;

	for(i=1;i<=j;i++)
	{
		printf("         ");
		if(i<=j/2+1)
		{
			for(g=1;g<=2*i;g++)
			printf("*");
			printf("\n");
		}
		
		 
	}
	
	return 0;
}

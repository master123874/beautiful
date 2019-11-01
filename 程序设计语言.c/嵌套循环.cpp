#include<stdio.h>
int main()
{
	int i,j;
	char ch='A',c='         ';
	for(i=0;i<6;i++)
	{
		for(j=0;j<=i;j++)
		printf("%c",c);
		printf("%c",ch++);
		printf("\n"); 
	}
	
	return 0;
 } 

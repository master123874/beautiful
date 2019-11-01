#include<stdio.h>
int main()
{
	int i,j,row=6,x=6;
	char ch='A';
	for(i=0;i<row;i++)
	{
	
		for(j=0;j<=i;j++)
		printf("%c",ch++);
		printf("\n");
	}
	
	return 0;
	
 } 

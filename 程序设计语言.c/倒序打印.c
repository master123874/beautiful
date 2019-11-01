#include<stdio.h>
int main()
{
	int i;
	int iarray[1];
	printf("please input 8 integer to array:");
	for(i=0;i<=1;i++)
	{
		scanf("%d",&iarray[i]);
		
	}
	
	getchar();
	printf("The array you inputed was:");
	for(i=1;i>=0;i--)
	{
		printf("%d",iarray[i]);
	}
	printf("\n");
 } 

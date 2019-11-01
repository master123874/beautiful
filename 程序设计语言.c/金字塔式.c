#include<stdio.h>
int main()
{
	int i,j,k;
	char ch;
	printf("Please input a capital:");
	scanf("%c",&ch);
	k=ch-'A'+1;
	for(i=0;i<k;i++)
	{
		for(j=0;j<=i;j++)
		printf(" ");
		for(j=0;j<k;j++)
		printf("%c",'A'+j);
		for(j=0;j<=i;j++)
		printf("%c",--ch);
		
		printf("\n");
	}
	
	return 0;


}

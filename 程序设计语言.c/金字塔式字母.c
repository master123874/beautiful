#include<stdio.h>
int main()
{
	int i,j,k,l,n;
	char ch;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ch='A';
		for(j=n-i;j>=1;j--)
		  printf(" ");
		for(k=1;k<=i;k++)
		  printf("%c",ch++);
		--ch;  
		for(l=1;l<i;l++)
		  
		  printf("%c",--ch);
		printf("\n");    
		    
	} 
	
	return 0;
} 

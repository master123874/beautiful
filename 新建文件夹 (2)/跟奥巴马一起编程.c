#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char ch;
	scanf("%d %c",&n,&ch);
	int i,j;
	for(i=0;i<n;i++)
	{
		if(i==0||i==n-1)
		{
			for(j=0;j<n;j++)
			  printf("%c",ch);
			printf("\n");  
		}
		else if(i==1)continue;
		else if((i+1)%2==0)
		{
			for(j=0;j<n;j++)
			{
				if(j==0||j==n-1)printf("%c",ch);
				else printf(" ");
			}
			printf("\n");
		}
	}
	
}

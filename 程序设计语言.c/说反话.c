#include<stdio.h>
#include<stdlib.h>
#define N 100000
int main()
{
	char s[90][90];
	int i,j,t=0;
    while(scanf("%s",&s[t])!=EOF)
    {
    	t++;
    	if(getchar()=='\n')
    	  break;
	}
	for(j=t-1;j>=0;j--)
	{
		printf("%s",s[j]);
		if(j>0) printf(" ");
	}
	return 0;
	
	
} 

#include<stdio.h>
#define A 500000
int main()
{
	int i=0,j;
	int k=0,d;
	char b[A];
	while(1)
	{
		scanf("%c",&b[i]);
		if(b[i]=='\n') break;
		i++;
	}
	char c[i];
	for(j=i-1;j>=0;j--)
	{
		if(k!=0)
		{
			
			for(d=k-1;d>=0;d--)
			{
				printf("%c",c[d]);
			}
			k=0;
			printf(" ");
			
		}
		
		else if(b[j]!=' ')
		{
			c[k]=b[j];
			k++;
			
		}

	}
	
	return 0;
}

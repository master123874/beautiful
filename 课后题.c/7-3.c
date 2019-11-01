#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char a[6][6],t[20];
	for(i=0;i<6;i++)
	  scanf("%s",a[i]);
	for(i=0;i<6;i++)
	{
		for(j=0;j<6-i-1;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
				printf("%s",a[j]);

			}
			printf("\n");
		}
    }
	
	return 0;  
	
} 

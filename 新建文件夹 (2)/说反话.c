#include<stdio.h>
#include<string.h>
int main()
{
	char a[81];
	gets(a);
	int i;
	int t;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			t=i;
			break;
		}
	}
	char b[81];
	int count=0,j,flag=0;
	for(i=strlen(a)-1;i>=t;i--)
	{
		if(a[i]==' '&&count!=0)
		{
			if(!flag)
			{
				for(j=count-1;j>=0;j--)
				{
					printf("%c",b[j]);
				}
				flag=1;
			}
			else
			{
				printf(" ");
				for(j=count-1;j>=0;j--)
				{
					printf("%c",b[j]);
				}
			}
			count=0;	
		}
		else if(a[i]!=' ')
		{
			b[count]=a[i];
			count++;
		}
	}
	if(!flag)
	{
		for(j=count-1;j>=0;j--)
		{
			printf("%c",b[j]);
		}
	}		
	else
	{
		printf(" ");
		for(j=count-1;j>=0;j--)
		{
			printf("%c",b[j]);
		}
	}
}

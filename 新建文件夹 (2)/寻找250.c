#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10000
int main()
{
	char a[N];
	gets(a);
	int i;
	int count=0,s=0;
	char t[20];
	for(i=0;i<strlen(a);i++)
	{
		if(isspace(a[i]))
		{
			count++;
			s=0;
			if(!strcmp(t,"250"))
			{
				printf("%d",count);
				return 0;
			}
		}
		else if(isdigit(a[i]))
		{
			t[s]=a[i];
			s++;
		}	
	}
	if(!strcmp(t,"250"))
		printf("%d",++count);		
}

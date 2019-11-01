#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#define N 1001
int main()
{
	int count=0;
	int i;
	char a[N],b[N];
	scanf("%s",a);
	scanf("%s",b);
	int j;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=-1)
		{
			for(j=0;j<strlen(b);j++)
			{
				if(b[j]!=-1)
				{
					if(a[i]==b[j])
					{
						count++;
						a[i]=-1;
						b[j]=-1;
						break;
					}
				}
			}
		}
	}
	if(count==strlen(b))printf("Yes %d",strlen(a)-count);
	else printf("No %d",strlen(b)-count);
	
}

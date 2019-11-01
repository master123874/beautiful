#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000];
	int i,j;
	gets(a);
	gets(b);
	strcat(a,b);
	int flag;
	printf("%c",a[0]);
	for(i=1;i<strlen(a);i++)
	{
		flag=1;
		for(j=0;j<i;j++)
		  if(a[j]==a[i])flag=0;
		if(flag)printf("%c",a[i]);  
	}
}

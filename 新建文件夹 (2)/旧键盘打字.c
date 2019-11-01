#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 100001
int ad(char t[])
{
	int i;
	for(i=0;i<strlen(t);i++)
	{
		if(t[i]==','||t[i]=='.'||t[i]=='+'||t[i]=='-')
		  return 1;
	}
	return 0;
}
int judge(char t[],char ch)
{
	int i;
	for(i=0;i<strlen(t);i++)
	{
		if(ad(t))
		{
			if(isupper(ch))return 0;
			else if(t[i]==toupper(ch))return 0;
		}
		else if(t[i]==toupper(ch))return 0;
	}
	return 1;
}
int main()
{
	char t[N];
	gets(t);
	char ch;
	int count=0;
	ch=getchar();
	while(ch!='\n')
	{
		if(judge(t,ch))
		{
			printf("%c",ch);
			count++;
		}
		ch=getchar();
	}
	if(!count)printf("\n");
}

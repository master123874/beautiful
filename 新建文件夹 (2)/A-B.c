#include<stdio.h>
#include<string.h>
#define N 10001
int judge(int n,char ch,char b[N])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(ch==b[i])return 0;
	}
	return 1;
}
int main()
{
	char a[N],b[N];
	gets(a);
	gets(b);
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if(judge(strlen(b),a[i],b))
		  printf("%c",a[i]);
	}
}

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10000
int judge(char *a)
{
	int i;
	int flag1=0,flag2=0,flag3=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>=65&&a[i]<=90)flag1=1;
		else if(a[i]>=97&&a[i]<=122)flag2=1;
		else if(a[i]>=48&&a[i]<=57)flag3=1;
	}
	if(flag1&&flag2&&flag3)return 1;
	return 0;
}
int main()
{
	char a[N];
	scanf("%s",a);
	if(strlen(a)>20||strlen(a)<12)printf("No");
	else
	{
		if(judge(a))printf("Yes");
		else printf("No");
	}
}

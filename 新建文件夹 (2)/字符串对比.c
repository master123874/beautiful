#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 11
int judge(char *a,char *b)
{
	int i;
	for(i=0;i<strlen(a);i++)
	  if(toupper(a[i])!=toupper(b[i]))return 0;
	return 1;  
}
int main()
{
	char a[N];
	char b[N];
	scanf("%s",a);
	scanf("%s",b);
	if(strlen(a)!=strlen(b))printf("1");
	else if(!strcmp(a,b))printf("2");
	else if(strlen(a)==strlen(b)&&judge(a,b))printf("3");
	else printf("4");
}

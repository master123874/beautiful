#include<stdio.h>
#include<string.h>
#define N 51
int main()
{
	char *p;
	char a[N];
	scanf("%s",a);
    p=a; 
	while(*p)p++;
	printf("%s",a);
	while(*(--p)!=a[0]) printf("%c",*p);
	printf("%c",a[0]);
} 

#include<stdio.h>
#include<string.h>
#define N 4
int main()
{
	char a[N];
	scanf("%s",a);
	int i;
	int t=strlen(a);
	if(t==3)
	{
		for(i=0;i<a[0]-48;i++)printf("B");
		for(i=0;i<a[1]-48;i++)printf("S");
		for(i=1;i<=a[2]-48;i++)printf("%d",i);
	}
	else if(t==2)
	{
		for(i=0;i<a[0]-48;i++)printf("S");
		for(i=1;i<=a[1]-48;i++)printf("%d",i);
	}
	else if(t==1) for(i=1;i<=a[0]-48;i++)printf("%d",i);
}

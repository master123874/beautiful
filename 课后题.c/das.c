#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		int t=a;
		a=b;
		b=t;
	}
	if(b>c)
	{
		int t=b;
		b=c;
		c=t;
	}
	if(a>c)
	{
		int t=a;
		a=c;
		c=t;
	}
	printf("%d",c);
}

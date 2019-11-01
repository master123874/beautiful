#include<stdio.h>
int main()
{
	int a,b;
	int i;
	scanf("%d:%d",&a,&b);
	if(a>=0&&a<12)printf("Only %02d:%02d.Too early to Dang.",a,b);
	else if(a==12&&b==0)printf("Only %02d:%02d.  Too early to Dang.",a,b);
	else if(a==12&&b!=0)
	{
		for(i=0;i<a+1;i++)printf("Dang");
	}
	else if(a>12&&b!=0&&a<=23)
	{
		for(i=0;i<a+1;i++)printf("Dang");
	}
	else if(a>12&&b==0&&a<=23)
	{
		for(i=0;i<a;i++)printf("Dang");
	}
}

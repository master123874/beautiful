#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l=4;
int judgepr(int n)
{
	if((n%4==0&&n%100!=0)||n%400==0)return 1;
	return 0;
} 
int week(int t,int a[],int p)
{
	int result=0;
	int i;
	
	for(i=1;i<t;i++)
	  result+=a[i];
	result+=p;
	l=(l+result)%7;
	return l;  
}
int main()
{
	int x;
	int i,j;
	scanf("%d",&x);
	int a[12]={31,0,31,30,31,30,31,31,30,31,30,31};
	if(judgepr(x)) a[2]=29;
	else a[2]=28;
	register z;
	int result=0;
	for(z=1999;z<=x;z++)
	{
		if(judgepr(z-1))result+=366;
		else result+=365;
	}
	l=(l+result)%7;
	int count=0;
	for(i=1;i<=12;i++)
	{
		if(week(i,a,13)==5)count++;
	}
	printf("%d年有%d个黑色星期天",x,count);
}


#include<stdio.h>
#include<stdlib.h>
typedef struct S
{
	int year;
	int month;
	int day;
	int com;
	int t;
}T;
int l=1;
void change(int *p,int *b,int *c,int d,int (*a)[]);
int gain(int e,int c,int b,int (*a)[],int d);
int judgepr(int n)
{
	if((n%100!=0&&n%4==0)||n%400==0)return 1;
	return 0;
}
int main()
{
	int m;
	scanf("%d",&m);
	register int i,j;
	T s[m];
	long day=0L;
	int t;
	int a[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	for(i=0;i<m;i++)
	 scanf("%d-%d-%d %d",&s[i].year,&s[i].month,&s[i].day,&s[i].com);
	for(i=0;i<m;i++)
	{
		for(j=1991;j<s[i].year;j++)
		{
			
			if(judgepr(j))
			{
				day+=366;
			}
			else
			{
				day+=365;	
			}
		}
		l=(l+day)%7;
		s[i].t=gain(s[i].year,s[i].month,s[i].day,a,s[i].com);
		change(&s[i].year,&s[i].month,&s[i].day,s[i].com,a);
		day=0;
		l=1;	
	}
	char b[7][20]={"星期一","星期二","星期三","星期四","星期五","星期六","星期日"}; 
	for(i=0;i<m;i++)
	{
		printf("%d年%02d月%02d日 %s",s[i].year,s[i].month,s[i].day,b[s[i].t-1]);
		if(i<m-1)printf("\n");
	}
	
}
int gain(int e,int c,int b,int (*a)[13],int d)
{
	int i;
	long day=0L;
	int temp=judgepr(e);
	for(i=1;i<c;i++)
	  day+=a[temp][i];
	day+=b;
	l=(l+day+d)%7;
	return l;  
}
void change(int *p,int *b,int *c,int d,int (*a)[13])
{
	int temp;
	while(d>0)
	{
		temp=judgepr(*p);
		d--;
		(*c)++;
		if(*c>a[temp][*b])
		{
			(*c)=1;
			(*b)++;
			if(*b==13)
			{
				(*b)=1;
				(*p)++;
			}
		}
		
	}
}						 

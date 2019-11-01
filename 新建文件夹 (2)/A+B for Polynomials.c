#include<stdio.h>
typedef struct s{
	int a;
	float b;
	int tag;
}S;
void sort(S *s,int num)
{
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(s[i].a<s[j].a)
			{
				S t=s[i];
				s[i]=s[j];
				s[j]=t;
			}	
		}
	}
}
void process(S *p,S *q,int m,int n) 
{
	int num=0;
	int i,j;
	S s[m+n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(q[i].a==p[j].a&&p[j].tag==0)
			{
				q[i].b+=p[j].b;
				p[j].tag=1;
			}
		}
		s[num]=q[i];
		num++;
	}
	for(j=0;j<n;j++)
	{
		if(!p[j].tag)
		  s[num++]=p[j];
	}
	printf("%d",num);
	if(num!=0)printf(" ");
	sort(s,num);
	for(i=0;i<num;i++)
	{
		printf("%d %.1f",s[i].a,s[i].b);
		if(i<num-1)printf(" ");
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	S p[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %f",&p[i].a,&p[i].b);
		p[i].tag=0;
	}
	int t;  
	scanf("%d",&t);
	S q[t];  
	for(i=0;i<t;i++)
	{
		scanf("%d %f",&q[i].a,&q[i].b);
		q[i].tag=0;
	}
	process(p,q,t,n);
}

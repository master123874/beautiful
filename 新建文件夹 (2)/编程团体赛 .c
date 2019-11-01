#include<stdio.h>
typedef struct
{
	int id,id1;
	int total;
}S;
int judge(S *p,int count,S t,int *s)
{
	int i;
	for(i=0;i<count;i++)
	  if(p[i].id==t.id)
	  {
	  	  *s=i;
	  	  return 1;
	  }
	return 0;  
	  
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	S p[n];
	S t;
	int s;
	int count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d-%d %d",&t.id,&t.id1,&t.total);
		if(!count)
			p[count++]=t;
		else
		{
			if(judge(p,count,t,&s))p[s].total+=t.total;
			else p[count++]=t;
		}
	}
	t=p[0];
	for(i=1;i<count;i++)
	{
		if(p[i].total>t.total)
		{
			t=p[i];
		}
	}
	printf("%d %d",t.id,t.total);
}

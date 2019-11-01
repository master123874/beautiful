#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6
typedef struct s{
	char name[N];
	struct s *next;
}S,*list;
list tail=NULL;
void create(list T)
{
	T=NULL;
}
void insert(char na[],list T)
{
	list t;
	t=(S *)malloc(sizeof(S));
	strcpy(t->name,na);
	if(!T)
	{
		T=t;
		tail=t;
		t->next=NULL;
	}
	else
	{
		tail->next=t;
		t->next=NULL;
		tail=t;
	}
}
int judge(list T,char na[])
{
	list t=T;
	while(t)
	{
		if(!strcmp(na,t->name))return 0;
		t=t->next;
	}
	return 1;
}
int main()
{
	list T;
	create(T);
	int n;
	scanf("%d",&n);
	int i,t,j;
	char na[N];
	int flag=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		for(j=0;j<t;j++)
		{
			scanf("%s",na);
			if(!flag)
			{
				insert(na,T);
				flag=1;
			}
			else if(judge(T,na))
			{
				insert(na,T);
			}
		}
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",na);
		if(judge(T,na)&&flag)
		{
			printf("%s",na);
			flag=0;
		}
		else if(judge(T,na))printf(" %s",na);
	}
	if(flag)
	{
		printf("No one is handsome");
	}
	free(T);
}

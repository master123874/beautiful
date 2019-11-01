#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 21
typedef struct s{
	char name[N];
	struct s *next;
}*Linklist,Lnode;
Linklist tail;
Linklist creat()
{
	Lnode *t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}
int isempty(Linklist head)
{
	if(head->next==NULL)return 1;
	return 0;
}
void insert(Linklist head,char a[N])
{
	Lnode *t=(Linklist)malloc(sizeof(Lnode));
	strcpy(t->name,a);
	tail->next=t;
	tail=t;
	tail->next=NULL;
}
void print(Linklist head)
{
	Lnode *t=head->next;
	if(!t)printf("Keep going...");
	while(t)
	{
		printf("%s\n",t->name);
		t=t->next;
	}
}
void destroy(Linklist head)
{
	Lnode *t=head;
	while(t)
	{
		free(t);
		t=t->next;
	}
}
int findit(char a[N],Linklist head)
{
	Lnode *t=head->next;
	while(t)
	{
		if(!strcmp(t->name,a))return 1;
		t=t->next;
	}
	return 0;
}
int main()
{
	int m,n,q;
	scanf("%d %d %d",&m,&n,&q);
	int i,j;
	Linklist head=creat();
	tail=head;
	char a[m][N];
	for(i=0;i<m;i++)scanf("%s",a[i]);
	for(i=q-1;i<m;i+=n)
	{
		if(isempty(head))
			insert(head,a[i]);
		else
		{
			while(findit(a[i],head))
			   i++;
			if(i<m)insert(head,a[i]);   
		}
	}
	print(head);
	destroy(head);	
} 

#include<stdio.h>
#include<stdlib.h>
typedef struct s{
	int data;
	struct s *next;
}Lnode,*Linklist;
Linklist creat()
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}
void initial(Linklist head,int n)
{
	int i;
	Lnode *t,*p=head;
	for(i=0;i<n;i++)
	{
		t=(Linklist)malloc(sizeof(Lnode));
		if(!t)return;
		scanf("%d",&t->data);
		t->next=NULL;
		p->next=t;
		p=t;
	}
}
void process(Linklist head,Linklist head1)
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->data=head->next->data;
	head1->next=t;
	t->next=NULL;
	int x=t->data;
	Lnode *p,*t1=head->next->next;
	while(t1)
	{
		if(t1->data<x)
		{
			p=(Linklist)malloc(sizeof(Lnode));
			p->data=t1->data;
			p->next=head1->next;
			head1->next=p;
		}
		else if(t1->data>x)
		{
			p=(Linklist)malloc(sizeof(Lnode));
			p->data=t1->data;
			t->next=p;
			t=p;
		}
		else 
		{
			p=(Linklist)malloc(sizeof(Lnode));
			p->data=t1->data;
			t->next=p;
			t=p;
		}
		t1=t1->next;
	}
	t->next=NULL;
}
void print(Linklist head)
{
	Lnode *t=head;
	while(t->next!=NULL)
	{
		t=t->next;
		printf("%d ",t->data);
	}
}
int main()
{
	int n;
	Linklist head;
	head=creat();
	scanf("%d",&n);
	initial(head,n);
	Linklist head1=creat();
	process(head,head1); 
	print(head1);
} 

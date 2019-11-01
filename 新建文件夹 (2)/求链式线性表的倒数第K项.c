#include<stdio.h>
#include<stdlib.h>
typedef struct s{
    int data;
    struct s *next;
}*Linklist,list;
static int length=0;
Linklist creat()
{
	list *t=(Linklist)malloc(sizeof(list));
	t->next=NULL;
	return t; 
}
void input(Linklist head)
{
	list *p=head;
	list *t=(Linklist)malloc(sizeof(list));
	scanf("%d",&t->data);
	while(t->data>=0)
	{
		p->next=t;
		p=t;
		length++;
		t=(Linklist)malloc(sizeof(list));
		scanf("%d",&t->data);
	}
	p->next=NULL;
}
void print(Linklist head,int n)
{
	if(length<n)
	{
		printf("NULL");
		return;
	}
	int count=0;
	list *p=head->next;
	while(count<length-n)
	{
		p=p->next;
		count++;
	}
	printf("%d",p->data);
}
int main()
{
    Linklist head=creat();
    int n;
    scanf("%d",&n);
    input(head);
    print(head,n);
}

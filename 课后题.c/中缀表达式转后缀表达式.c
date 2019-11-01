#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 10000
typedef struct s{
	char data;
	struct s *next;
}Lnode,*Linklist;
Linklist creat()
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}
void push(char t,Linklist a)
{
	Lnode *t1;
	t1=(Linklist)malloc(sizeof(Lnode));
	t1->data=t;
	t1->next=a->next;
	a->next=t1;
}
int isempty(Linklist t)
{
	if(t->next==NULL)return 1;
	return 0;
}
int retu(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '(':return 3;
		case ')':return 0;			
	}
}
void pop(Linklist t,int *a)
{
	if(isempty(t))return;
	Lnode *p=t->next;
	t->next=p->next;
	*a=retu(p->data);
	free(p);
}
int main()
{
	char ch[N];
	Linklist a,b;
	a=creat();
	b=creat();
	gets(ch);
	int i;
	for(i=0;i<strlen(ch);i++)
	{
		if(isalpha(ch[i]))
		  push(ch[i],a);
		else
		{
			if(isempty(b))push(ch[i],b);
			else
			{
				int t;
				int s;
				pop(b,&t);
				s=retu(ch[i]);
				if(s>t)push(ch[i],b);
				printf("%d",t);
			}
		}
	}
	if(a->next->next==NULL)printf("%c",a->next->data);

} 

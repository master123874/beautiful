#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100
typedef struct s{
	int a,b;
	struct s *next;
}Lnode,*Linklist;
Linklist creat()
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}
void insert(Linklist head,int n)
{
	int i;
	Lnode *t,*p=head;
	char c,d;
	for(i=0;i<n;i++)
	{
		t=(Linklist)malloc(sizeof(Lnode));
		scanf(" %c%d,%d%c",&c,&t->a,&t->b,&d);
		p->next=t;
		p=t;
	}
	p->next=NULL;
}
void print(Linklist head)
{
	Lnode *t=head;
	int flag=0;
	if(!t->next)
	{
		printf("0");
		return;
	}
	while(t->next!=NULL)
	{
		t=t->next;
		if(t->a==0)printf("");
		else if(t->b==0)printf("%d",t->a);
		else if(t->a==-1&&t->b==1)printf("-X",t->a);
		else if(t->a==1)printf("X^%d",t->b);
		else if(t->b==1)printf("%dX",t->a);
		else printf("%dX^%d",t->a,t->b);
		
		if(t->next!=NULL)
		{
			if(t->next->a>0)printf("+");
		}
			
	}
}
void add(Linklist head1,Linklist head2,Linklist head3)
{
	Lnode *t=head1->next,*t1=head2->next,*t2=head3;
	while(t1&&t)
	{
		if(t1->b==t->b)
		{
			t1->a=t->a+t1->a;
			t2->next=t1;
			t2=t1;
			t1=t1->next;
			t=t->next;
		}
		else if(t1->b>t->b)
		{
			t2->next=t;
			t2=t;
			t=t->next;
		}
		else
		{
			t2->next=t1;
			t2=t1;
			t1=t1->next;
		}
	}
	while(t)
	{
		t2->next=t;
		t2=t;
		t=t->next;
	}
	while(t1)
	{
		t2->next=t1;
		t2=t1;
		t1=t1->next;
	}
}
void minus(Linklist head1,Linklist head2,Linklist head3)
{
	Lnode *t=head1->next,*t1=head2->next,*t2=head3;
	while(t&&t1)
	{
		if(t->b==t1->b)
		{
			t->a=t->a-t1->a;
			if(t->a!=0)
			{
				t2->next=t;
				t2=t;
			}
			t1=t1->next;
			t=t->next;
		}
		else if(t->b>t1->b)
		{
			t1->a=-t1->a;
			if(t1->a!=0)
			{
				t2->next=t1;
				t2=t1;
			}
			t1=t1->next;
		}
		else
		{
			if(t->a!=0)
			{
				t2->next=t;
				t2=t;
			}
			t=t->next;
		}
	}
	while(t)
	{
		if(t->a!=0)
		{
			t2->next=t;
			t2=t;
		}
		t=t->next;
	}
	while(t1)
	{
		t1->a=-t1->a;
		if(t1->a!=0)
		{
			t2->next=t1;
			t2=t1;
		}
		t1=t1->next;
	}
}
void getresult(Linklist head1,int m)
{
	Lnode *t=head1->next;
	int result=0;
	while(t)
	{
		result+=t->a*pow(m,t->b);
		t=t->next;
	}
	printf("%d",result);
}
void getit(Linklist head1,Linklist head2)
{
	Lnode *t=head1->next,*t2=head2;
	while(t)
	{
		if(t->a!=0&&t->b!=0)
		{
			t->a=t->a*t->b;
			t->b-=1;
			t2->next=t;
			t2=t;
		}
		t=t->next;
	}
	t2->next=NULL;
}
void multiply(Linklist head1,Linklist head2,Linklist head3)
{
	int x,y;
	Lnode *t=head1->next,*t1=head2->next,*t2=head3;
	Lnode *s;
	while(t)
	{
		x=t->a;
		y=t->b;
		while(t1)
		{
			s=(Linklist)malloc(sizeof(Lnode));
			s->a=x*t1->a;
			s->b=y+t1->b;
			t2->next=s;
			t2=s;
			t1=t1->next;
		}
		t1=head2->next;
		t=t->next;
	}
	t2->next=NULL;
}
void process(Linklist head)
{
	Lnode *t=head->next;
	while(t)
	{
		Lnode *t1=t->next,*prev=t;
		while(t1)
		{
			if(t1->b==t->b)
			{
				t->a=t->a+t1->a;
				prev->next=t1->next;
				free(t1);
				t1=prev->next;
				continue;
			}
			prev=t1;
			t1=t1->next;
		}
		t=t->next;
	}
}
void sort(Linklist head,Lnode t1[],int *count)
{
	Lnode *t=head->next;
	while(t)
	{
		t1[*count].a=t->a;
		t1[*count].b=t->b;
		t=t->next;
		(*count)++;
	}
}
sort1(Lnode a[],int count,Linklist head)
{
	int i,j;
	int change=1;
	Lnode *t=head->next;
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(a[i].b>a[j].b)
			{
				Lnode z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	int s=0;
	while(t)
	{
		t->a=a[s].a;
		t->b=a[s].b;
		t=t->next;
		s++;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	Linklist head1;
	head1=creat();
	insert(head1,n);
	Linklist head2=creat();
	int m;
	scanf("%d",&m);
	insert(head2,m);
	Linklist head3=creat();
	multiply(head1,head2,head3);
	process(head3);
	Lnode a[N];
	int count=0;
	sort(head3,a,&count);
	sort1(a,count,head3);
	print(head3);
}

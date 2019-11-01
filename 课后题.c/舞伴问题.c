#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char name[20];
	char sex;
}Person;
typedef Person DataType;
typedef struct s{
	DataType p1;
	struct s *next;
}*Queue,Lnode;
Queue tail1,tail2;
Queue InitQueue()
{
	Queue t;
	t=(Queue)malloc(sizeof(Lnode));
	t->next=NULL;
	if(!t)return NULL;
	return t;
}
void EnQueue(Queue t,Person t2,int flag)
{
	Queue t1=(Queue)malloc(sizeof(Lnode));
	if(flag==1)
	{
		t1->p1=t2;
		
		tail1->next=t1;
		tail1=t1;
		t1->next=NULL;
	}
	else
	{
		t1->p1=t2;
		tail2->next=t1;
		tail2=t1;
		t1->next=NULL;
	}
}
int QueueEmpty(Queue t)
{
	Queue s=t->next;
	if(!s)return 1;
	return 0;
}
Person DeQueue(Queue t)
{
	Lnode *s=t->next;
	Person t1=s->p1;
	t->next=s->next;
	free(s);
	return t1;
}
Person QueueFront(Queue t)
{
	if(t->next)return t->next->p1;
}
void print(Queue t)
{
	Lnode *s=t->next;
	while(s)
	{
		printf("%s",s->p1.name);
		s=s->next;
	}
}
void DancerPartner(Person dancer[],int num)
{
	int i;
	Person p;
	Queue Mdancers,Fdancers;
	Mdancers=InitQueue();
	Fdancers=InitQueue();
	tail1=Mdancers;
	tail2=Fdancers;
	for(i=0;i<num;i++)
	{
		p=dancer[i];
		if(p.sex=='F')EnQueue(Fdancers,p,2);
		else EnQueue(Mdancers,p,1);
	}
	printf("The dancing partners are:\n \n");
	while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
	{
		p=DeQueue(Fdancers);
		printf("%s       ",p.name);
		p=DeQueue(Mdancers);
		printf("%s\n",p.name);
	}
	if(!QueueEmpty(Fdancers))
	{
		p=QueueFront(Fdancers);
		printf("%s will be the first to get a partner. \n",p.name);
	}
	else if(!QueueEmpty(Mdancers))
	{
		p=QueueFront(Mdancers);
		printf("%s will be the first to get a partner. \n",p.name);
	}
}
int main()
{
	int num;
	Person p[20];
	printf("请输入跳舞的男士与女士的总人数：");
	scanf("%d", &num);
	if(num > 20) 
	  exit(0);
	while(num <= 0)
    {
        printf("输入错误，请重新输入跳舞的人数："); 
        scanf("%d", &num);
    }
    int i;
    for(i=0;i<num;i++)
    {
    	printf("请输入第%d个人的姓名与性别,性别输入'F'或'M':",i+1);
    	scanf("%s %c",p[i].name,&p[i].sex);
	}
	DancerPartner(p, num);
}

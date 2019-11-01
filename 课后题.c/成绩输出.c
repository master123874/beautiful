#include<stdio.h>
#include<stdlib.h>
typedef struct S
{
	int num;
	char name[20];
	int score;
	struct S *next;
}*linklist,Lnode;
linklist creat()
{
	int icount=0;
	linklist head=NULL,pend,pnew;
	pend=pnew=(linklist)malloc(sizeof(Lnode));
	scanf("%d %s %d",&pnew->num,pnew->name,&pnew->score);
	while(1)
	{
		if(pnew->num==0)break;
		icount++;
		if(icount==1)
		{
			pnew->next=head;
			pend=pnew;
			head=pnew;
		}
		else
		{
			pnew->next=NULL;
			pend->next=pnew;
			pend=pnew;
			
		}
		pnew=(linklist)malloc(sizeof(Lnode));
		scanf("%d %s %d",&pnew->num,pnew->name,&pnew->score);
	}
	free(pnew);
	return head;	
}
void print(linklist head)
{
	linklist temp;
	temp=head;
	while(temp)
	{
		printf("%d",temp->score);
		temp=temp->next;
	}
}
int main()
{
	linklist head;
	head=creat();
	print(head);
	return 0;
}

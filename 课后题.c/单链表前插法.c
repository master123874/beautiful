#include<stdio.h>
#include<stdlib.h>
typedef struct S
{
	int data;
	struct S *next;
}*Linklist,Lnode;
void destroylist(Linklist phead);
void output(Linklist phead);
Linklist initial(int n);
int main()
{
	int n;
	scanf("%d",&n);
	Linklist phead;
	phead=initial(n);
	output(phead);
	destroylist(phead);
	
} 
void destroylist(Linklist phead)
{
	while(phead)
	{
		free(phead);
		phead=phead->next; 
	}
}
void output(Linklist phead)
{
	Linklist temp;
	temp=phead;
	while(temp)
	{
		printf("%d ",temp->next->data);
		temp=temp->next;
	}
}
Linklist initial(int n)
{
	int i;
	Linklist phead,pnew;
	phead=(Linklist)malloc(sizeof(Lnode));
	if(!phead) exit(0);
	phead->next=NULL;
	for(i=0;i<n;i++)
	{
		pnew=(Linklist)malloc(sizeof(Lnode));
		scanf("%d",&pnew->data);
		pnew->next=phead->next;
		phead->next=pnew;
	}
	return phead;
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define ERROR 0
#define OK 1
typedef struct student
{
	int score[3];
	char a[20];
	char name[20];
	struct student *next;
}*linknode,Lnode;
int icount=0;
linknode initial(int n)
{
	linknode phead=NULL,pnew,pend;
	pnew=pend=(Lnode *)malloc(sizeof(Lnode));
	int i;
	for(i=0;i<n;i++)
	{
		icount++;
		scanf("%s %s %d %d %d",pnew->a,pnew->name,&pnew->score[0],&pnew->score[1],&pnew->score[2]);
		if(icount==1)
		{
			pnew->next=phead;
		    pend=pnew;
		    phead=pnew;
		}
		else
		{
			pnew->next=NULL;
			pend->next=pnew;
			pend=pnew;
		}
		pnew=(Lnode *)malloc(sizeof(Lnode));
	}
	return phead;
}
void output(linknode phead)
{
	Lnode *temp;
	temp=phead;
	while(temp)
	{
		printf("%s,%s,%d,%d,%d\n",temp->a,temp->name,temp->score[0],temp->score[1],temp->score[2]);
		temp=temp->next;
	}
}
void destroy(linknode phead)
{
	
	while(phead)
	{
		free(phead);
		phead=phead->next;
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	linknode phead;
	phead=initial(n);
	output(phead);
	destroy(phead);
} 

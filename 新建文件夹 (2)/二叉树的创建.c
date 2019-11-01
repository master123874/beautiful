#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct tree{
	char data;
	struct tree *rchild;
	struct tree *lchild;
	struct tree *parent;
}*Linklist,Lnode;
static int count=0,count1=0,count2=0;
int flag=0,top=0,top1,base=0;
Linklist queue[N];
Linklist queue1[N];
char stack[N];
void creattree(Linklist *root,Linklist tail)
{
	char t;
	scanf("%c",&t);
	if(t=='#')*root=NULL;
	else
	{
		*root=(Linklist)malloc(sizeof(Lnode));
		(*root)->data=t;
		(*root)->parent=tail;
		tail=*root;
		creattree(&((*root)->lchild),tail);
		creattree(&((*root)->rchild),tail);
	}
}
void print1(Linklist root)
{
	if(root)
	{
		printf("%c",root->data);
		print1(root->lchild);
		print1(root->rchild);
	}
}
void print2(Linklist root)
{
	if(root)
	{
		print2(root->lchild);
		printf("%c",root->data);
		print2(root->rchild);
	}
}
void print3(Linklist root)
{
	if(root)
	{
		print3(root->lchild);
		print3(root->rchild);
		printf("%c",root->data);
	}
}
void find(Linklist root)
{
	if(root)
	{
		if(root->lchild==NULL&&root->rchild==NULL)count++;
		else if((root->lchild==NULL&&root->rchild!=NULL)||(root->lchild!=NULL&&root->rchild==NULL))count1++;
		else if(root->lchild&&root->rchild)count2++;
		find(root->lchild);
		find(root->rchild);
	}
}
void printy(Linklist root)
{
	if(root)
	{
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			printf("%c:",root->data);
			Lnode *t=root->parent;
			while(t)
			{
				stack[top]=t->data;
				top++;
				t=t->parent;
			}
			int i;
			for(i=top-1;i>=0;i--)printf("%c",stack[i]);
			printf("\n");
			top=0;  /*重置全局变量*/
		}
		printy(root->lchild);
		printy(root->rchild);
	}
}
void printgs(Linklist root,int level,int n)
{
	if(root)
	{
		if(level==n&&!root->lchild&&!root->rchild)count++;
		printgs(root->lchild,level+1,n);
		printgs(root->rchild,level+1,n);
	}
}
void printcx(Linklist root)
{
	queue[base]=root;
	top++;
	int low=0;
	while(low!=top)
	{
		Lnode *t=queue[low];
		low++;
		if(t->lchild)
		{
			queue[top]=t->lchild;
			top++;
		}
		if(t->rchild)
		{
			queue[top]=t->rchild;
			top++;
		}
	}
	int i;
	for(i=base;i<top;i++)printf("%c",queue[i]->data);
}
Linklist find1(char t,char t1,Linklist root)
{
	if(flag==2)return;
	if(root)
	{
		if(root->data==t)
		{
			Lnode *t2=root->parent;
			while(t2)
			{
				queue[top]=t2;
				top++;
				t2=t2->parent;
			}
			flag++;
		}
		if(root->data==t1)
		{
			Lnode *t2=root->parent;
			while(t2)
			{
				queue1[top1]=t2;
				top1++;
				t2=t2->parent;
			}
			flag++;
		}
		find1(t,t1,root->lchild);
		find1(t,t1,root->rchild);
	}
}
void create(Linklist *t,char *a,char *b,int n)
{
	if(n==0)*t=NULL;
	else
	{
		int t1=0;
		while(a[0]!=b[t1])t1++;
		*t=(Linklist)malloc(sizeof(Lnode));
		(*t)->data=b[t1];
		create(&(*t)->lchild,a+1,b,t1);
		create(&(*t)->rchild,a+t1+1,b+t1+1,n-t1-1);
	}
}
void create1(Linklist *t,char *a,char *b,int n)
{
	if(n==0)*t=NULL;
	else
	{
		int t1=0;
		while(a[n-1]!=b[t1])t1++;
		*t=(Linklist)malloc(sizeof(Lnode));
		(*t)->data=b[t1];
		create1(&(*t)->rchild,a+t1,b+t1+1,n-t1-1);
		create1(&(*t)->lchild,a,b,t1);
	}
}
int main()
{
	Linklist root=NULL;
	char a[N],b[N];
	scanf("%s",a);
	scanf("%s",b);
	create1(&root,b,a,strlen(a));
	print1(root);
}

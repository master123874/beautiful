#include<stdio.h>
#include<stdlib.h>
typedef struct s{
	struct s *next;
	int a,b,c;
}Lnode,*Linklist;
int m,n;
Linklist creat()
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}

int judge(char ch,int x,int y)
{
	if(ch=='0'&&x>=1&&x<=m&&y>=1&&y<=n)return 1;
	return 0;
}
int flag=0;
void dfs(char (*a)[n+1],int x,int y)
{
	if(flag)return;
	printf("%d %d",m,n);
	if(x==m&&y==n)
	{
		printf("(%d,%d,%d)",x,y,0);
		flag=1;
		return;
	}
	int i;
	int b[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	for(i=1;i<=4;i++)
	{
		x+=b[i-1][0];
		y+=b[i-1][1];
		if(judge(a[x-1][y-1],x,y))
		{
			dfs(a,x,y);
		}
		else return; 
	}
}
void print(Linklist head)
{
	Lnode *t=head->next;
	while(t)
	{
		printf("(%d,%d,%d)",t->a,t->b,t->c);
		t=t->next;
	}
}
int main()
{	
	Linklist head=creat();
	scanf("%d %d",&m,&n);
	char mi[m][n+1];
	int i;
	for(i=0;i<m;i++)scanf("%s",mi[i]);
	dfs(mi,1,1);
}

#include<stdio.h>
#include<stdlib.h>
#define N 10
#define M 5
typedef struct s{
	int x,y;    /*记录位置*/ 
	int fx;   /*记录方向*/ 
	struct s *next;
}*Linklist,Lnode;
static int flag=0;  /*标记迷宫是否具有通路*/ 
int m,n;  /*迷宫行数与列数*/ 
const int xa[M][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
int startx,starty;
int count=1;
int sum=0;
static Linklist head;
Linklist creat()
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}
void destroy()
{
	Lnode *t=head;
	while(t)
	{
		free(t);
		t=t->next;
	}
}
void print(int sum)
{
	int i,j; 
	printf("该迷宫的第%d条通路:",sum);
	Lnode *t=head->next;
	while(t)
	{
		printf("(%d,%d,%d)->",t->x,t->y,t->fx);
		t=t->next;
	}
	destroy();
	head->next=NULL;
	printf("\n");
}
int cango(int x,int y,int t)
{
	if(x>=1&&x<=m&&y>=1&&y<=n&&t==0)return 1;
	
	return 0;
}
void push(int x1,int y1,int f)
{
	Lnode *t;
	t=(Linklist)malloc(sizeof(Lnode));
	t->x=x1;
	t->y=y1;
	t->fx=f;
	t->next=head->next;
	head->next=t;
}
void pop()
{
	Lnode *t=head->next;
	head->next=t->next;
	free(t);
}
void dfs(int x,int y,int (*a)[n+1],int (*t)[n+1])
{
	int i;
	if(x==m&&y==n)
	{
		flag=1;
		sum++;
		print(sum);
		return;
	}
	for(i=1;i<M;i++)
	{
		int newx=x+a[i][0];
		int newy=y+a[i][1];
		if(cango(newx,newy,a[newx][newy])&&!t[newx][newy])
		{
			push(x,y,i);
			t[newx][newy]=1;
			a[newx][newy]=1;
			dfs(newx,newy,a,t);
			t[newx][newy]=0;
			a[newx][newy]=0;
			pop();
		}
	}
}
int main()
{
	srand(time(NULL));   /*种子*/ 
	int i,j;
	printf("\t\t\t\t\t欢迎进入迷宫模式\n");
	while(1)
	{
		printf("输入1进入迷宫2退出:");
		int t;
		scanf("%d",&t);
		switch(t)
		{
			case 1:{
				printf("请输入迷宫的行数与列数:");
				scanf("%d %d",&m,&n);
				int a[m+1][n+1];
				int s[m+1][n+1];
				for(i=1;i<=m;i++)
				  for(j=1;j<=n;j++)
				    s[i][j]=0;
				flag=0;
				printf("请输入迷宫起点:");
				scanf("%d %d",&startx,&starty);
				printf("0代表可行,1代表障碍:\n",count);
				printf("1代表方向右,2代表下,3代表左,4代表上\n"); 
				for(i=1;i<=m;i++)
				{
					for(j=1;j<=n;j++)
					  scanf("%d",&a[i][j]);
				}
				s[startx][starty]=1;
				a[startx][starty]=1;
				head=creat();
				dfs(startx,starty,a,s);
				if(!flag)printf("该迷宫无通路!");
				break;
			}
			case 2:exit(0);
			default:printf("输入了无效的指令请重新输入\n");
		}
	}  	
}

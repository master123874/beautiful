#include<stdio.h>
#include<stdlib.h>
#define row 100
#define col 100
struct mark{
	int a,b;
};
typedef struct element{
	int i,j,d;  
}element;
typedef struct Linkstack{
	element elem;
	struct Linkstack *next;
}*SLinkstack,Linklist;
void initstack(SLinkstack *L)
{
	*L=NULL;
}

int stack_empty(SLinkstack *L)
{
	if(*L==NULL)
		return 1;
	else
		return 0;
}

void push_stack(SLinkstack *L,element E)
{
	SLinkstack P;
	P=(SLinkstack)malloc(sizeof(Linklist));
	P->elem=E;
	P->next=*L;
	*L=P;
}
void pop(SLinkstack *L,element *E)
{
	SLinkstack P;
	*E=(*L)->elem;
	P=*L;
	*L=(*L)->next;
	free(P);

}
void built_maze(int maze[row][col])
{
	int x,y;
	int m,n;
	printf("请输入迷宫的行列数（用逗号隔开）：");
	scanf("%d,%d",&m,&n);
	printf("请输入迷宫各行各列的数据（用空格隔开）：\n");
	for(x=1;x<=m;x++)
	{
		for(y=1;y<=n;y++)
		{
			scanf("%d",&maze[x][y]);
		}
	}
	printf("迷宫生成中……\n");
	printf("迷宫显示为：\n");
	for(x=1;x<=m;x++)
	{
		for(y=1;y<=n;y++)
			printf("%3d",maze[x][y]);
		printf("\n");
	}
}
void maze_path(int maze[row][col],int dir[4][2],struct mark start,struct mark end)
{
	int i1,j1,d1;
	int x,y;
	element elem,E;
	SLinkstack L1,L2;
	initstack(&L1);
	initstack(&L2);
	maze[start.a][start.b]=2;  
	elem.i=start.a;
	elem.j=start.b;
	elem.d=-1; 
	push_stack(&L1,elem);
	while(!stack_empty(&L1))
	{
		pop(&L1,&elem);
		i1=elem.i;
		j1=elem.j;
		d1=elem.d+1;
		while(d1<4)   
		{
			x=i1+dir[d1][0];
			y=j1+dir[d1][1];
			if(x==end.a&&y==end.b&&maze[x][y]==0)  
			{
				elem.i=i1;
				elem.j=j1;
				elem.d=d1;
				push_stack(&L1,elem);
				while(L1)      
				{
					pop(&L1,&E);
					push_stack(&L2,E);
				}
				while(L2)
				{
					pop(&L2,&E);
					printf("(%d,%d,%d)\n",E.i,E.j,E.d);
				}
				return;
			}
			if(maze[x][y]==0)
			{
				maze[x][y]=2;  
				elem.i=i1;
				elem.j=j1;
				elem.d=d1;
				push_stack(&L1,elem);
				i1=x;
				j1=y;
				d1=-1;
			}
			d1++;
		}
	}
	printf("此迷宫无出路");
}

void main()
{
	int maze[row][col];
	struct mark start,end;   
	int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};   
	printf("***********************************************************************************************\n");
	printf("\t***************             欢迎使用迷宫模拟程序              ***************\n");
	printf("***********************************************************************************************\n");
	built_maze(maze);
	printf("请输入入口的横纵坐标：");
	scanf("%d,%d",&start.a,&start.b);
	printf("请输入出口的横纵坐标：");
	scanf("%d,%d",&end.a,&end.b);
	printf("0为东，1为南，2为西，3为北，-1为出路\n");
	maze_path(maze,dir,start,end);
	printf("按任意键继续");
	getchar();
}


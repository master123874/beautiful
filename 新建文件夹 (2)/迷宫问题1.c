
#include<stdio.h>
#include<stdlib.h>
int Move[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; /*控制方向*/ 
int stack[100][3];  /*保存路径*/ 
static int top;
int flag;
int m,n;  /*迷宫的行数与列数*/ 
int startx,starty;
int sum=0;
void Print(int sum)
{
	printf("迷宫的第%d条路径如下:\n",sum);
	printf("1代表方向右,2代表方向下,3代表方向左,4代表方向上,0代表出口\n"); 
	int i,j;
	int t=0;
	stack[top][2]=0;
	for(i=0;i<top;i++)
		printf("(%d,%d,%d)->",stack[i][0],stack[i][1],stack[i][2]);
	printf("出口\n");
	printf("\n");
}
int cango(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=n)return 1;
	return 0;
}
void dfs(int x,int y,int (*M)[n+1],int (*s)[n+1])
{
	if(x==m&&y==n)
	{
		sum++;
		flag=1; 
		Print(sum);
	}
	else
	{
		int i;
		for(i=0;i<4;i++) 
		{
			int newx=x+Move[i][0]; 
			int newy=y+Move[i][1]; 
			if(cango(newx,newy)&&!M[newx][newy]&&!s[newx][newy]) 
			{
				s[newx][newy]=1;
				M[newx][newy]=1;  /*记录这条路已经走过*/ 
				stack[top][2]=i+1;
				top++; 
				stack[top][0]=newx;
				stack[top][1]=newy;
				dfs(newx,newy,M,s);  		/*遍历*/ 
				s[newx][newy]=0;
				M[newx][newy]=0;   			/*回溯*/ 
				top--;	
			}
		}
	}
}
int main()
{
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
				sum=0;    /*初始化路数*/ 
				for(i=1;i<=m;i++)
				  for(j=1;j<=n;j++)
				    s[i][j]=0;     /*对路线初始化*/ 
				flag=0;
				printf("请输入迷宫起点:");
				scanf("%d %d",&startx,&starty);
				printf("0代表可行,1代表障碍:\n");
				printf("请输入迷宫各点的状态:\n");
				for(i=1;i<=m;i++)
				{
					for(j=1;j<=n;j++)
					  scanf("%d",&a[i][j]);
				}
				if(a[startx][starty]==1)printf("输入的起点无法通行"); 
				else
				{
					s[startx][starty]=1;
					top=0;
					stack[top][0]=startx;
					stack[top][1]=starty;
					a[startx][starty]=1;
					dfs(startx,starty,a,s);
					if(!flag)printf("该迷宫无通路!");
				}
				break;
			}
			case 2:exit(0);
			default:printf("输入了无效的指令请重新输入\n");
		}
	}  	
}

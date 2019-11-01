#include<stdio.h>
int x,y;
int cango(int x1,int y1,char ch)
{
	if(x1>=1&&x1<=x&&ch=='0'&&y1<=y&&y1>=1)return 1;
	return 0;
}
void dfs(char (*a)[20],int x1,int y1)
{
	int i;
	if(x1==x&&y1==y)
	{
		printf("(%d,%d,%d)",x,y,0);
		return;
	}
	int b[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	for(i=0;i<4;i++)
	{
		int t=x1,t1=y1;
		x1+=b[i][0];
		y1+=b[i][1];
		if(cango(x1,y1,a[x1-1][y1-1]))
		{
			dfs(a,x1,y1);
			printf("(%d,%d,%d)",t,t1,i+1);
		}
	}
} 
int main()
{
	printf("请输入迷宫的行号与列号:");
	scanf("%d %d",&x,&y);
	char a[x][y+1];
	int i;
	for(i=0;i<x;i++)scanf("%s",a[i]);
	dfs(a,1,1);
}

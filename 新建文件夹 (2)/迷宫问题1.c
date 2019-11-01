
#include<stdio.h>
#include<stdlib.h>
int Move[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; /*���Ʒ���*/ 
int stack[100][3];  /*����·��*/ 
static int top;
int flag;
int m,n;  /*�Թ�������������*/ 
int startx,starty;
int sum=0;
void Print(int sum)
{
	printf("�Թ��ĵ�%d��·������:\n",sum);
	printf("1��������,2��������,3��������,4��������,0�������\n"); 
	int i,j;
	int t=0;
	stack[top][2]=0;
	for(i=0;i<top;i++)
		printf("(%d,%d,%d)->",stack[i][0],stack[i][1],stack[i][2]);
	printf("����\n");
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
				M[newx][newy]=1;  /*��¼����·�Ѿ��߹�*/ 
				stack[top][2]=i+1;
				top++; 
				stack[top][0]=newx;
				stack[top][1]=newy;
				dfs(newx,newy,M,s);  		/*����*/ 
				s[newx][newy]=0;
				M[newx][newy]=0;   			/*����*/ 
				top--;	
			}
		}
	}
}
int main()
{
	int i,j;
	printf("\t\t\t\t\t��ӭ�����Թ�ģʽ\n");
	while(1)
	{
		printf("����1�����Թ�2�˳�:");
		int t;
		scanf("%d",&t);
		switch(t)
		{
			case 1:{
				printf("�������Թ�������������:");
				scanf("%d %d",&m,&n);
				int a[m+1][n+1];
				int s[m+1][n+1];
				sum=0;    /*��ʼ��·��*/ 
				for(i=1;i<=m;i++)
				  for(j=1;j<=n;j++)
				    s[i][j]=0;     /*��·�߳�ʼ��*/ 
				flag=0;
				printf("�������Թ����:");
				scanf("%d %d",&startx,&starty);
				printf("0�������,1�����ϰ�:\n");
				printf("�������Թ������״̬:\n");
				for(i=1;i<=m;i++)
				{
					for(j=1;j<=n;j++)
					  scanf("%d",&a[i][j]);
				}
				if(a[startx][starty]==1)printf("���������޷�ͨ��"); 
				else
				{
					s[startx][starty]=1;
					top=0;
					stack[top][0]=startx;
					stack[top][1]=starty;
					a[startx][starty]=1;
					dfs(startx,starty,a,s);
					if(!flag)printf("���Թ���ͨ·!");
				}
				break;
			}
			case 2:exit(0);
			default:printf("��������Ч��ָ������������\n");
		}
	}  	
}

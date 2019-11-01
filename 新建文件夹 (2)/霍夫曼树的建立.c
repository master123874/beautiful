#include<stdio.h>
#include<string.h>
#define N 6
#define M 2*N-1
typedef struct s{
	int weight;
	int lchild;
	int rchild;
	int parent;
}Tree;
int stack[N][50];
int top[N]={0};
void select(int n,Tree *s,int *s1,int *s2)
{
	int i,j;
	int count=0;
	int flag=0;
	for(i=1;i<=n;i++)
	{
		if(!s[i].parent)
		{
			if(!flag)
			{
				*s1=i;
				flag=1;
			}
			else if(s[*s1].weight>s[i].weight)
			{
				*s1=i;
			}
		}
	}
	flag=0;
	for(i=1;i<=n;i++)
	{
		if(!s[i].parent&&i!=*s1)
		{
			if(!flag)
			{
				*s2=i;
				flag=1;
			}
			else if(s[*s2].weight>s[i].weight)
			{
				*s2=i;
			}
		}
	}
	
}
void print1(Tree *s)
{
	int i;
	for(i=1;i<=N;i++)
	{
		printf("%c:",64+i);
		int t=i;
		while(s[t].parent!=-1)
		{
			if(s[s[t].parent].lchild==t)
			{
				stack[i][top[i]]=0;
				top[i]++;
			}
			else if(s[s[t].parent].rchild==t)
			{
				stack[i][top[i]]=1;
				top[i]++;
			}
			t=s[t].parent;
		}
		int j;
		for(j=top[i]-1;j>=0;j--)printf("%d",stack[i][j]);
		printf("\n");
	}
}
void process(Tree *s)
{
	int i;
	for(i=N+1;i<=M;i++)
	{
		s[i].lchild=0;
		s[i].rchild=0;
		s[i].parent=0;
		s[i].weight=0;
		int s1,s2;
		select(i-1,s,&s1,&s2);
		s[i].weight=s[s1].weight+s[s2].weight;
		s[i].lchild=s1;
		s[i].rchild=s2;
		s[s1].parent=i;
		s[s2].parent=i;            /*处理过程*/ 
	}
	s[M].parent=-1;  /*将根节点的父亲职位-1,方便后面操作*/ 
	print1(s); 
}
int main()
{
	int i,t;
	Tree S[M];
	for(i=1;i<=N;i++)
	{
		scanf("%d",&t);
		S[i].lchild=0;
		S[i].rchild=0;
		S[i].parent=0;
		S[i].weight=t;
	}	
	process(S);
	char a[50];
	getchar();
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	{
		int t=a[i]-64;
		int j;
		for(j=top[t]-1;j>=0;j--)printf("%d",stack[t][j]);
	}
	printf("\n");
	getchar();
	char b[1000];
	scanf("%s",b);
	Tree t2=S[M];
	int t1;
	for(i=0;i<strlen(b);)
	{
		t2=S[M];
		for(;i<strlen(b);i++)
		{
			if(t2.lchild==0&&t2.rchild==0)
			{
				printf("%c",64+t1);
				break;
			}
			if(b[i]=='0')
			{
				t1=t2.lchild;
				t2=S[t2.lchild];
			}
			else if(b[i]=='1')
			{
				t1=t2.rchild;
				t2=S[t2.rchild];
			}
		}
	}
	printf("%c",64+t1);
} 

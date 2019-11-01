#include<stdio.h>
#include<string.h>
#define N 1000
typedef struct s{
	int count;
	char c;
}S;
typedef struct tree{
	int weight;
	int parent;
	int lchild;
	int rchild;
}Tree;
static int co=0;
int judge(S *s,char t)
{
	int i;
	for(i=0;i<co;i++)
		if(s[i].c==t)
		{
			s[i].count++;
			return 0;
		}
	return 1;	
}
void insertsort(S *s)
{
	int i,j;
	for(i=1;i<co;i++)
	{
		S t=s[i];
		j=i-1;
		while(j>=0&&t.c<=s[j].c)
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=t;
	}
}
void select(Tree *s,int t,int *s1,int *s2)
{
	int i;
	int flag=0;
	for(i=0;i<=t;i++)
	{
		if(!s[i].parent)
		{
			if(!flag)
			{
				*s1=i;
				flag=1;
			}
			else if(s[*s1].weight>s[i].weight)*s1=i;
		}
	}
	flag=0;
	for(i=0;i<=t;i++)
	{
		if(!s[i].parent&&i!=*s1)
		{
			if(!flag)
			{
				*s2=i;
				flag=1;
			}
			else if(s[*s2].weight>s[i].weight)*s2=i;
		}
	}
}
void creattree(S *s,Tree *t)
{
	int i;
	for(i=0;i<co;i++)
	{
		t[i].parent=0;
		t[i].lchild=0;
		t[i].rchild=0;
		t[i].weight=s[i].count;
	}                            /*初始化前端哈 弗曼书*/ 
	
	for(i=co;i<=2*co-2;i++)
	{
		t[i].parent=0;
		t[i].lchild=0;
		t[i].rchild=0;
		t[i].weight=0;
		int s1,s2;
		select(t,i-1,&s1,&s2);
		t[i].weight=t[s1].weight+t[s2].weight;
		t[i].lchild=s1;
		t[i].rchild=s2;
		t[s1].parent=i;
		t[s2].parent=i;
	}
}
int getindex(S *s,char t)
{
	int i;
	for(i=0;i<co;i++)
		if(s[i].c==t)return i;
}
void process(char *t,S *s,Tree *z)
{
	int i;
	for(i=0;i<strlen(t);i++)
	{
		int t1=getindex(s,t[i]);
		int t2=z[t1].parent;
		char b[100];
		int top=0;
		while(t2)
		{
			if(z[t2].lchild==t1)
			{
				b[top]='0';
				top++;
			}
			else if(z[t2].rchild==t1)
			{
				b[top]='1';
				top++;
			}
			t1=t2;
			t2=z[t1].parent;
		}
		int j;
		for(j=top-1;j>=0;j--)printf("%c",b[j]);
	}
	printf("\n");
}
void process1(char *t,S *s,Tree *z)
{
	int i;
	Tree t2=z[2*co-2];
	int t1;
	for(i=0;i<strlen(t);)
	{
		t2=z[2*co-2];
		for(;i<strlen(t);i++)
		{
			if(t2.lchild==0&&t2.rchild==0)
			{
				printf("%c",s[t1].c);
				break;
			}
			if(t[i]=='0')
			{
				t1=t2.lchild;
				t2=z[t2.lchild];
			}
			else if(t[i]=='1')
			{
				t1=t2.rchild;
				t2=z[t2.rchild];
			}
		}
	}
	printf("%c",s[t1].c);
}
void getlength(Tree *z,int t1)
{
	int count,i;
	float sum=0;
	for(i=0;i<co;i++)
	{
		int t=i;
		count=0;
		while(z[t].parent)
		{
			count++;
			t=z[t].parent;
		}
		sum+=(float)z[i].weight/t1*count;
	}
	printf("%.2f",sum);
}
int main()
{
	int i;
	S s[N];
	char t[N];
	int t5=0;
	char v=getchar();
	while(v!='#')
	{
		t[t5]=v;
		t5++;
		v=getchar();
	}
	t[t5]='\0';
	for(i=0;i<strlen(t);i++)
	{
		s[i].count=0;
		if(!co)
		{
			s[co].count++;
			s[co].c=t[i];
			co++;
		}
		else
		{
			if(judge(s,t[i]))
			{
				s[co].count++;
				s[co].c=t[i];
				co++;
			}
		}
	}
	insertsort(s);
	Tree z[2*co-2];
	creattree(s,z);
	process(t,s,z);
	getchar();
	gets(t);
	process1(t,s,z);
	printf("\n");
	getlength(z,t5);
}


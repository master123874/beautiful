#include<stdio.h>
#include<string.h>
#define N 6
typedef struct{
	char k[N],z[N];
}S;
int trial(char *a,char *t,S t1[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((!strcmp(a,t1.k)&&!strcmp(t,t1.z))||(!strcmp(a,t1.z)&&!strcmp(t,t1.k)))return 1;
	}
	return 0;
}
int judge(int t,char (*a)[N],S t1[],int n)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<t;j++)
		{
			if(trial(a[i],a[j],t1,n))return 0;
		}
	}
	return 1;
}
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	int i,j;
	S t[n];
	for(i=0;i<n;i++)
	  scanf("%s %s",t[i].k,t[i].z);
	int t1;
	for(i=0;i<m;i++)
	{
		scanf("%d",&t1);
		char a[t1][N];
		for(j=0;j<t;j++)scanf("%s",a[j]);
		if(judge(t1,a,t,n))puts("Yes");
		else puts("No");
	}
}

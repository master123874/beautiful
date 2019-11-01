#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int judge(int m,char (*a)[5],char *ch)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(!strcmp(a[i],ch))return 0;
	}
	return 1;
}
int findindex(int m,char (*a)[5],char *ch)
{
	int i;
	for(i=0;i<m;i++)
	  if(!strcmp(a[i],ch))return i+1;
}
int findit(int count,char (*t)[5],char *ch)
{
	int i;
	for(i=0;i<count;i++)
	  if(!strcmp(t[i],ch))return 1;
	return 0;  
}
int prime(int m)
{
	int i;
	for(i=2;i*i<=m;i++)
	{
		if(m%i==0)return 0;
	}
	return 1;
}
int main()
{
	int m,n;
	scanf("%d",&m);
	char a[m][5];
	int i;
	for(i=0;i<m;i++)scanf("%s",a[i]);
	char ch[5];
	scanf("%d",&n);
	char t[m][5];
	int count=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",ch);
		if(judge(m,a,ch))printf("%s: Are you kiding?\n",ch);
		else
		{
			if(!count)
			{
				strcpy(t[count],ch);
				count++;
				if(findindex(m,a,ch)==1)printf("%s: Mystery Award\n",ch);
				else if(prime(findindex(m,a,ch)))printf("%s: Minion\n",ch);
				else printf("%s: Chololate\n",ch);
			}
			else
			{
				if(findit(count,t,ch))printf("%s: Checked\n",ch);
				else
				{
					strcpy(t[count],ch);
					count++;
					if(findindex(m,a,ch)==1)printf("%s: Mystery Award\n",ch);
					else if(prime(findindex(m,a,ch)))printf("%s: Minion\n",ch);
					else printf("%s: Chololate\n",ch);	
				}
			}
		}
	}
}

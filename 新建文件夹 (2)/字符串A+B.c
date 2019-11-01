#include<stdio.h>
#include<string.h>
#define N 1000001 
int judge(int n,char t[],char ch)
{
	int i;
	for(i=0;i<n;i++)
	  if(t[i]==ch)return 0;
	return 1;  
}
int main()
{
	char name[N];
	int i,j;
	char t[N],count=0;
	for(i=0;i<2;i++)
	{
		gets(name);
		for(j=0;j<strlen(name);j++)
		{
			if(!count)
			{
				t[count]=name[j];
				count++;
			}
			else 
			{
				if(judge(count,t,name[j]))
				{
					t[count]=name[j];
					count++;
				}
			}
		}
	}
	printf("%s",t);
}

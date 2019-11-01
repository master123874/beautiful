#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000
int main()
{
	int n;
	scanf("%d",&n);
	int S[n*2][N+1];
	char a[n][N],b[n][N];
	int i,j;
	for(i=0;i<n;i++)
	   scanf("%s %s",a[i],b[i]);
	int t,t2;
	int a1,b1;
	int s;
	for(i=0;i<n;i++)
	{
		memset(S[i],0,N+1);
		memset(a[i],'\0',N);
		memset(b[i],'\0',N); 
		memset(S[n+i],0,N+1);
	}
	for(i=0;i<n;i++)
	{
		if(strlen(a[i])<strlen(b[i]))s=strlen(b[i]);
		else s=strlen(a[i]);
		t=s;
		for(a1=strlen(a[i])-1,b1=strlen(b[i])-1;a1>=0&&b1>=0;a1--,b1--)
		{
			S[i][s]+=a[i][a1]+b[i][b1]-96;
			if(S[i][s]>=10)
			{
				S[i][s]%=10;
				S[i][s-1]=S[i][s]/10;	
			}
			s--;	
		}
		if(a1>0)
		{
			for(;a1>=0;a1--)
			{
				S[i][s]+=a[i][a1]-48;
				if(S[i][s]>=10)
				{
					S[i][s]%=10;
					S[i][s-1]=S[i][s]/10;
				}
				s--;
			}
		}
		else if(b1>0)
		{
			for(;b1>=0;b1--)
			{
				S[i][s]+=b[i][b1]-48;
				if(S[i][s]>=10)
				{
					S[i][s]%=10;
					S[i][s-1]=S[i][s]/10;
				}
				s--;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=t;j++)
		{
			printf("%d",S[i][j]);
		}
	}
	
} 
	

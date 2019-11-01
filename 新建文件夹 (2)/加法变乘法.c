#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct s
{
	int c[N][2];
}S;
int main()
{
	int n,i;
	scanf("%d",&n);
	int j; 
	int a[n][2];
	for(i=0;i<n;i++)
	  for(j=0;j<2;j++)
	    scanf("%d",&a[i][j]);
	int count[n];
	int flag[n];
	S p[n];
	for(i=0;i<n;i++)
	{
		flag[i]=0;
		count[i]=0;
	}
	int result=0;
	int c[n][2];
	int k,g,l;
	int t=0;
	int sum=0;
	for(i=0;i<n;i++)
	{
		result=0;
		for(j=1;j<=a[i][0]/2;j++)
		{
			result+=j;
			if(result>=a[i][0])break;
		}	
		if(result==a[i][0])
		{
			for(k=1;k<j;k++)
			{
				for(g=k+2;g<j;g++)
				{
					sum=0;
					for(l=1;l<=j;l++)
					{
						if(l==k||l==g)continue;	
						else if(l==k+1||l==g+1)sum+=l*(l-1);
						else sum+=l;
					}
					if(sum==a[i][1])
					{
						flag[i]=1;
						p[i].c[count[i]][0]=k;
						p[i].c[count[i]][1]=g;
						count[i]++;
					}
				}
			}
		}	
	}
	int flag1=0;
	int s=0;
	for(i=0;i<n;i++)
	{
		if(!flag[i]&&!flag1)
		{
			printf("NONE");
			flag1=1;
		}
		else if(!flag[i]&&flag1)
		{
			printf("\nNONE");
		}
		else if(flag[i]&&!flag1)
		{
			for(j=0;j<count[i];j++)
			{
				printf("(%d,%d)",p[i].c[j][0],p[i].c[j][1]);
			}
			flag1=1;
		}
		else if(flag[i]&&flag1)
		{
			printf("\n");
			for(j=0;j<count[i];j++)
			{
				printf("(%d,%d)",p[i].c[j][0],p[i].c[j][1]);
			}
		}		
	}   
} 


#include<stdio.h>
#define N 6
typedef struct{
	int score,select;
	char answer[N];
	int num;
}S;

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j;
	S a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i].score,&a[i].num,&a[i].select);
		for(j=0;j<a[i].select;j++)
		  scanf(" %c",&a[i].answer[j]);
	}
	int k;
	int num;
	char t[N];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("(%d",&num);
			for(k=0;k<num-1;k++)
			  scanf(" %c",&t[k]);
			scanf(" %c)",&t[k]);  
			
		}
	}
	for(k=0;k<num;k++)
			 printf(" %c",t[k]);
    
}

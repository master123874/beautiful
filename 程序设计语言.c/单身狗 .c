#include<stdio.h>
#include<stdlib.h>
struct s
{
	int husband,wife;
}*p;
void sortof(int n,int temp[]);
int tosearch(int *a,int n,int p);
void judge(int flag[],int a[],int n,struct s p);
int main()
{
	int m;
	scanf("%d",&m);
	p=(struct s *)malloc(sizeof(struct s)*m);
	int i;
	for(i=0;i<m;i++)
	  scanf("%d %d",&p[i].husband,&p[i].wife);
	int n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	int count=0;
	int flag[n];
	for(i=0;i<n;i++)flag[i]=0;
	for(i=0;i<m;i++)
	{
		if(tosearch(a,n,p[i].husband)&&tosearch(a,n,p[i].wife))
		{
			count++;
			judge(flag,a,n,p[i]);
		}
	}   
	printf("%d\n",n-count*2); 
	int flag1=0;
	int count1=0;
	int temp[n-count*2];
	for(i=0;i<n;i++)
	  if(!flag[i])temp[count1++]=a[i];
	sortof(n-count*2,temp);
	for(i=0;i<n-count*2;i++)
	{
		printf("%d",temp[i]);
		if(i<n-count*2-1)printf(" ");
	}  
	free(p);
}

void sortof(int n,int temp[])
{
	int i,j;
	int change=1;
	int a;
	for(i=0;i<n-1&&change;i++)
	{
		change=0;
		for(j=0;j<n-i-1;j++)
		  if(temp[j]>temp[j+1])
		  {
		  	  a=temp[j];
		  	  temp[j]=temp[j+1];
		  	  temp[j+1]=a;
		  	  change=1;
		  }
	}
}
int tosearch(int *a,int n,int p)
{
	int i;
	for(i=0;i<n;i++)
	  if(a[i]==p)return 1;
	return 0;
}
void judge(int flag[],int a[],int n,struct s p1)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==p1.husband||a[i]==p1.wife)
		  flag[i]=1;
	}
}

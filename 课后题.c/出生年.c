#include<stdio.h>
#include<string.h>
#define N 6
int getnumber(int m)
{
	int count=0;
	while(m)
	{
		m/=10;
		count++;
	}
	return count;
}
int getdifference(int i,int m,int t[])
{
	int j;
	for(j=0;j<i;j++)
	 if(t[j]==m)return 0;
	return 1; 
}
void confr(int t[],int m,int *num)
{
	int i=0;
	if(getnumber(m)<4)
	{
		for(;i<4-getnumber(m);i++)t[i]=0;
	}
	while(m)
	{
		t[i]=m%10;
		if(getdifference(i,m%10,t)&&i)(*num)++;
		m/=10;
		i++;
	}
}
void getresult(int m,int n)
{
	int i,j;
	int t[4];
	int s=0;
	while(m<=m+1)
	{
		int num=1;
		confr(t,m,&num);
		if(num==n)
		{
			printf("%d %.4d",s,m);
			return;
		}
		else
		{
			m++;
			s++;
		}
	}
}
int main()
{
	int i;
	int m,n;
	scanf("%d %d",&m,&n);
	getresult(m,n);
}

#include<stdio.h>
#define N 10
void reverse(char *S,int n)
{
	int t=n/2;
	int i;
	for(i=0;i<=t;i++)
	{
		char t=S[i];
		S[i]=S[n-i];
		S[n-i]=t;
	}
}
void print(int x)
{
	printf("%d",x);
	int count=0;
	char S[N];
	int flag=x>=0?1:0; 
	if(!flag)x=-x;
	while(x)
	{
		S[count]=x%10+48;
		count++;
		if(count%3==0)
			S[count++]=',';
	}
	if(!flag)S[count]='-';
	reverse(S,count);
	printf("%s",S);
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int a=m+n;
	print(a);
}

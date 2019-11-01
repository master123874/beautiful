#include<stdio.h> 
#include<string.h>
#define N 21
int retu(int a)
{
	if(a==0)return 10;
	return a;
}
int main()
{
	char a[N];
	scanf("%s",a);
	char b[2][N];
	int i,j;
	for(i=0;i<2;i++)scanf("%s",b[i]);
	int num;
	int c[40]={0};   /*±£´æ´ğ°¸*/ 
	int t2=0,t1=strlen(a)-1;
	int t=0;
	for(i=strlen(b[0])-1,j=strlen(b[1])-1;i>=0&&j>=0;i--,j--)
	{
		t+=b[0][i]+b[1][j]-96;
		c[t2]+=t%retu(a[t1]-48);
		num=t/retu(a[t1]-48);
		t1--;
		if(num)t=num;
		else t=0;
		t2++;
	}
	while(i>=0)
	{
		t+=b[0][i]-48;
		c[t2]+=t%retu(a[t1]-48);
		num=t/retu(a[t1]-48);
		t1--;
		if(num)
		 	t=num;
		else t=0;
		t2++;
		i--;
	}
	while(j>=0)
	{
		t+=b[1][j]-48;
		c[t2]+=t%retu(a[t1]-48);
		num=t/retu(a[t1]-48);
		t1--;
		if(num)
		 	t=num;
		else t=0;
		t2++;
		j--;
	}
	if(t)c[t2++]=t;
	while(!c[t2-1])t2--;
	for(i=t2-1;i>=0;i--)
	{
		printf("%d",c[i]);
	}
}

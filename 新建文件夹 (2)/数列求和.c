#include<stdio.h>
int main()
{
	int i;
	int n,m;
	scanf("%d %d",&m,&n);
	int j=0;
	int a[100000];
	int flag=0;
	int t;
	if(n==0)
	{
		printf("0");
		return 0;
	}
	else
	{
		for(i=n;i>=1;i--,j++)
		{
			t=i*m+flag;
			a[j]=t%10;
			flag=t/10;
		}
		if(flag>0)
		{
			a[j]=flag;
			j++;
		}
		for(i=j-1;i>=0;i--)printf("%d",a[i]);
	}
}

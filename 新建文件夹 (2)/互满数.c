#include<stdio.h>
#include<stdlib.h>

int factor_sum(int n)
{
	int i;
	int sum=0;
	for(i=1;i<n;i++)
	  if(n%i==0)sum+=i;
	return sum;
}
int isfriend(int a,int b,int c,int d)
{
	if(a==d&&b==c)return 1;
	return 0;
}
int main()
{

	int i,j;
	
	int x;
	
	scanf("%d",&x);
	int a[x];
	for(i=1;i<=x;i++)
	   a[i]=factor_sum(i);
	for(i=1;i<=x;i++)
	{
		if(a[i]!=-1)
		{
			for(j=i+1;j<=x;j++)
			{
				if(isfriend(i,j,a[i],a[j]))
                {
                    printf("(%d,%d)",i,j);
				    a[j]=-1;
                }
			}
        }

	}
}


#include<stdio.h>
#include<stdlib.h>
#define M 3001
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
	int a[M];
	printf("There are following friendly numbers from 1 to 3000\n");
	for(i=1;i<=3000;i++)
	   a[i]=factor_sum(i);
	for(i=1;i<=3000;i++)
	{
		if(a[i]!=-1)
		{
			for(j=i+1;j<=3000;j++)
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


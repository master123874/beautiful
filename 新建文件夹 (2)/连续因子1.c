#include<stdio.h>
#include<math.h>

int main()
{
	int N,n,prad;
	scanf("%d",&N);
	int i,j;
	int start=0,len=0;
	for (i=2;i<=sqrt(N);i++)
	{
		prad=1;
		for (j=i;(j*prad)<=N;j++)
		{
			prad*=j;
			if (N%prad==0&&len<(j-i+1))
			{
				start=i;
				len=j-i+1;
			}
		}	
	}
	if (len==0)
	{
		printf("1\n%d",N);
	}
	else
	{
		printf("%d\n",len);
		printf("%d",start);
		for (j=(start+1);j<(start+len);j++)
		{
			printf("*%d",j);
		}
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int ans(int n,int m,int length)
{
	if(n%m==0)return ans(n/m,m+1,length+1);
	else return length;
}
int main()
{
	int n;
	int length=0,L,element=0;
	scanf("%d",&n);
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			L=ans(n/i,i+1,1);
			if(L>length)
			{
				element=i;
				length=L;
			}
		}
	}
	if(length==0)
	{
		printf("1\n%d",n);
		return 0;
	}
	printf("%d\n",length);
	printf("%d",element);
	for(i=1;i<length;i++)
	 printf("*%d",element+i);
	
}

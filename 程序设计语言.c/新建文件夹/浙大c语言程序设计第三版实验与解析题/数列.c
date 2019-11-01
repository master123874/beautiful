#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define B 50
int main()
{
	int i,j,k,flag=1,b,c;
	long int a[B],N;
	scanf("%ld",&N);
	for(i=2;i<N&&N%2==0;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
			else flag=1;
		
		}
		if(flag)
		{
			a[k]=i;
			k++;
			
		}
	}
	for(b=0;b<k;b++)
	{
		for(c=0;c<k;c++)
		{
			if(a[b]+a[c]==N)
			{
				printf("%ld=%ld+%ld\n",N,a[b],a[c]);
				exit(0);
			}
		}
	}
	
	return 0;
   

}

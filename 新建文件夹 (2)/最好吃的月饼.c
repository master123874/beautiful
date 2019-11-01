#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			for(k=j+1;k<5;k++)
			printf("%d %d %d\n",i,j,k);
		}
	}
	 
}

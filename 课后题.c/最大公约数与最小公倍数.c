#include<stdio.h>
int main()
{
	int m,n;
	int temp;
	scanf("%d%d",&m,&n);
	if(m>n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	int i;
	for(i=m;i>=1;i--)
	  if(m%i==0&&n%i==0)
	  {
	  	  printf("%d",i);
	  	  break;
	  }
	for(i=n;i<=m*n;i++)
	{
		if(i%m==0&&i%n==0)
		{
			printf(" %d",i);
			break;
		}
	} 
	return 0; 
}

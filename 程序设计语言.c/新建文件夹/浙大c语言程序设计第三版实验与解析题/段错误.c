#include<stdio.h>
#include<math.h>
int isj(int n);
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	for(i=2;n%2==0&&i<n;i++)
	{
		if(isj(i)==0&&isj(n-i)==0)
		{
			printf("%d=%d+%d\n",n,i,n-i); 
			break;
		}
		else continue;
    } 
	
	return 0; 
}
int isj(int n)
{
	if(n==2) return 0;
	int j;
	for(j=2;j<sqrt(n);j++)
	{
		if(n%j==0) break;
		
	}
	if(n%j==0) return 1;
	else return 0;

	
}
 

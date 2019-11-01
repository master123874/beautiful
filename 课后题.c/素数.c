#include<stdio.h>
#include<math.h>
int main()
{
	int flag=1;
	int n;
	scanf("%d",&n);
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			flag=0;
			break;
		}
	}
	if(flag)printf("%d",n);
	else printf("what 'the fuck");
} 

#include<stdio.h>
#include<string.h>
#define N 1000005
int main()
{
	char a[N];
	scanf("%s",a);
	register int i,j,k;
	long long count=0l,s=0l,count1=0l;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='P')
		{
			count++;
		}
		if(a[i]=='A')
		{
			count1+=count;
		}
		if(a[i]=='T')
		{
			s+=count1;
		}
	}
	printf("%lld",s%1000000007);	
} 

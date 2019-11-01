#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int n;
	char a[N];
	scanf("%s%d",a,&n);
	int i,j,b=strlen(a);
	int count=1;
	for(i=0;i<b;i++)
	{
		for(j=i+1;j<b;j++)
		{
			if(a[i]!=a[j])break;
			else count++;
		}
		if(count==n) printf("%c",a[i]);
		
	}
} 

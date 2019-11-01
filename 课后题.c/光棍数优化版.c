#include<stdio.h>
int main()
{
	char a[100];
	int i;
	int n;
	int x=0,j=0;
	scanf("%d",&n);
	for(i=1;;i++)
	{
		x=10*x+1;
		a[j++]=x/n+'0'; 
		if(x%n==0)
		{
			char *s=a;
			while(*s=='0')s++;
			printf("%s %d",s,i);
			return 0;
		}
		x=x%n;
	}
}

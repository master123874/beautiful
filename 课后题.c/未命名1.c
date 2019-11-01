#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int m,n;
	char a[20];
	int len;
	char ch;
	int d,i;
	int count=0;
	while(scanf("%d%c%d=%s",&m,&ch,&n,a)!=EOF)
	{
		d=0;
		len=strlen(a);
		if(strcmp("?",a)!=0)
		{
			for(i=0;i<len;i++)
		    {
			    d=d+(a[i]-'0')*pow(10,len-i-1);
		    }
			if(ch=='+')
			{
				if(m+n==d) count++;
			}
			else if(ch=='-')
			{
				if(m-n==d) count++;
			}
		}
	}
	printf("%d",count);
	
} 

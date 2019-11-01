#include<stdio.h>
#include<string.h>

void Delete(int n,char str[])
{
	int j,s;
	s=strlen(str);
	for (j=n;j<s;j++)
	{
		str[j]=str[j+1];
	}
}

int main()
{
	
	char A[10001];
	char B[10001];
	gets(A);
	gets(B);
	int i,j,a,b;
	a=strlen(A);
	b=strlen(B);
	for (i=0;i<a;i++)
	{
		int flag=0;
		for (j=0;j<b;j++)
		{
			if (A[i]==B[j])
			{
				Delete(i,A);
				flag=1;
			}
		}
		if(flag)i--; 
	}
	puts(A);
	return 0;
}

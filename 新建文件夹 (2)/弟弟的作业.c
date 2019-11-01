
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,cnt=0,a,b,s;
	char c1,ch[5];
	while (scanf("%d%c%d=%s",&a,&c1,&b,ch)!=EOF)
	{
		if (strcmp(ch,"?")==0)
		{
			continue;
		}
		s=0;
		for (i=0; ch[i]; i++)
		{
			s=s*10+(ch[i]-'0');
		}
		if (c1=='-')
		  b=-b;
		if (a+b==s)
		 cnt++;
	}
	cout<<cnt;
	return 0;
}


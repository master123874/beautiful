#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 10
#define M 13
const char b[M][4]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const char c[M][4]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
static int count=0;
int retu(char *a)
{
	int i;
	int t=0;
	for(i=0;i<strlen(a);i++)
		t=t*10+a[i]-48;
	return t;
}
void print(char *a)
{
	int i;
	for(i=1;i<M;i++)
	{
		if(!strcmp(c[i],a))
		{
			count+=i*13;
			break;
		}
	}	
	for(i=0;i<M;i++)
	{
		if(!strcmp(b[i],a))
		{
			count+=i;
			break;
		}
	}
}
void sperate(char *t,char *t1,char *a)
{
	char *t2=a;
	int i=0;
	while(*t2!=' '&&*t2!='\0')
	{
		t[i]=*t2;
		i++;
		t2++;
	}
	if(i==strlen(a))
	  t1[0]='\0';
	else
	{
		while(*t2==' ')t2++;
		i=0;
		while(*t2!='\0')
		{
			t1[i]=*t2;
			i++;
			t2++;
		}
		t1[i]='\0';
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	char a[N];
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a);
		if(isdigit(a[0]))
		{
			int t=retu(a);
			if(t>=169)continue;
			if(t<13)
			{
				if(t==0)printf("tret\n");
				else printf("%s\n",b[t]);
			}
			else if(t%13==0)printf("%s\n",c[t/13]);
			else if(t%13&&t/13)printf("%s %s\n",c[t/13],b[t%13]);
		}
		else if(isalpha(a[0]))
		{
			count=0;
			char t1[N],t2[N];
			sperate(t1,t2,a);
			print(t1); 
			print(t2);
			printf("%d\n",count);
		}
	}
}

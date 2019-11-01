#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5000
#define M 10
int reverse(char *a)
{
	int i;
	int t=strlen(a);
	for(i=0;i<t/2;i++)
	{
		if(a[i]!=a[t-i-1])return 0;
	}
	return 1;
}
void add(char *a)
{
	char *s=(char *)malloc(sizeof(char)*(strlen(a)+1));
	char *b=a;
	while(*b!='\0')b++;
	b--;   /*回到上一个元素*/
	int t=0;  /*临时下表变量*/
	int i;
	int ys=0;  /*保存相加后的余数*/ 
	for(i=0;i<strlen(a);i++)
	{
		int s1=a[i]+*b-96+ys;
		s[t]=s1%10;
		t++;
		b--;
		if(s1>=10)ys=1;
		else ys=0;
	} 
	if(ys)
	{
		for(i=strlen(a);i>0;i--)a[i]=s[t-i]+48;
		a[0]='1';
		a[strlen(a)+1]='\0';
	}
	else for(i=strlen(a)-1;i>=0;i--)a[i]=s[t-i-1]+48;     /*加48是为了让其字符串输出时以数字形式展示*/ 
	
}
void printz(char *a)
{
	printf("%s",a);
}
void printreverse(char *a)
{
	int i;
	printf(" + ");
	for(i=strlen(a)-1;i>=0;i--)printf("%c",a[i]);
	printf(" = ");
}
int main()
{
	char a[N];
	scanf("%s",a);
	int i;
	for(i=0;i<M;i++)
	{
		if(reverse(a))
		{
			printf("%s is a palindromic number.",a);
			return 0;
		}
		else
		{
			printz(a);
			printreverse(a);
			add(a);
			printf("%s\n",a);
		}
	}
	printf("Not found in 10 iterations.");
	return 0;
}

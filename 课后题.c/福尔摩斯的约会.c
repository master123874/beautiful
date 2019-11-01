#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define N 61
#define n 4
char a[n][N];
int temp;
void select1(char ch)
{
	switch(ch)
	{
		case 'A':printf("MON ");break;
		case 'B':printf("TUE ");break;
		case 'C':printf("WED ");break;
		case 'D':printf("THU ");break;
		case 'E':printf("FRI ");break;
		case 'F':printf("SAT ");break;
		case 'G':printf("SUN ");break;
	}
}
void select2(char ch)
{
	if(isupper(ch))
		printf("%02d:",ch-55);
	else if(isdigit(ch))
		printf("%02d:",ch-'0');
}
int search(char (*p)[N])
{
	int i;
	int t=2;
	for(i=0;i<strlen(p)&&i<strlen(p+1);i++)
	{
		if(p[t][i]==p[t+1][i]&&isalpha(p[t][i]))
		  return i;
	}
}
char search1(char (*p)[N])
{
	int i,j;
	int t=0;
	for(i=0;i<strlen(p[t])&&i<strlen(p[t+1]);i++)
	{
		if(a[0][i]>='A'&&a[0][i]<='G'&&p[t+1][i]==p[t][i])
	    {
	    	temp=i;
	    	return p[t][i];
		}		
	}
}
char search2(char (*p)[N])
{
	int i;
	int t=0;
	for(i=temp+1;i<strlen(p[t])&&i<strlen(p[t+1]);i++)
	{
		if(p[t][i]==p[t+1][i]&&(a[0][i]>='A'&&a[0][i]<='N'||isdigit(p[t][i])))
		  return p[t][i]; 		
	}
}
int main()
{
	int i;
	for(i=0;i<n;i++)
	  scanf("%s",a[i]);
	select1(search1(a));
	select2(search2(a));
	printf("%02d",search(a));		
} 

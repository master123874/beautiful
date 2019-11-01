#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char ch;
    int a[4]={0,0,0,0};
    ch=getchar();
    while(ch!='\n')
    {
    	if(isalpha(ch))a[0]++;
    	else if(isdigit(ch))a[1]++;
    	else if(isspace(ch))a[2]++;
    	else a[3]++;
    	ch=getchar();
	}
	int i;
	for(i=0;i<4;i++)
	  printf("%d ",a[i]);
}

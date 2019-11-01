#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 101
int main()
{
    int n;
    char a[N];
    gets(a);
    scanf("%d",&n);
    char *p;
    int i;
    p=(char *)malloc(sizeof(char)*(strlen(a)+1));
    strcpy(p,a);
    n=n%strlen(a);
    for(i=0;i<strlen(a);i++)
    {
    	if(n%strlen(a)==0) break;
    	if(i-n<0) a[strlen(a)-abs(i-n)]=p[i];
    	else a[i-n]=p[i];
	}
	printf("%s",a);
    free(p);
}

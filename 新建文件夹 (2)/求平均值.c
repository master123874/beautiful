#include<stdio.h>
#include<string.h>
#define N 1001
int main()
{
    char a[N];
    int n;
    scanf("%s %d",a,&n);
    int i=0;
    int j=0;      /*±£´æÓàÊı*/
    int t,count=0;
    int coun=0;
    char *p=a;
    if(a[0]-48<n&&strlen(a)==1)
    {
    	printf("%d %d",0,a[0]-48);
    	return 0;
	}
    for(;i<strlen(a);i++)
    {
        j=j*10+(a[i]-'0');
        a[count]=(char)(j/n+48);
        j=j-n*(j/n);
        count++;
    }
    while(*p=='0')p++;
    printf("%s %d",p,j);
}


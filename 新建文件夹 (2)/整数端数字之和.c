#include<stdio.h>
#include<string.h>
#define N 10001
int main()
{
    char a[N],b[N];
    gets(a);
    gets(b);
    int i,j;
    char c[N];
    int flag=0;
    int count=0;
    for(i=0;i<strlen(a);i++)
    {
        for(j=0;j<strlen(b);j++)
        {
            if(a[i]==b[j])
            {
            	flag=1;
            	break;
			}
        }
        if(!flag)
        {
            c[count]=a[i];
            count++;
        }
    }
    printf("%s",c);
}
